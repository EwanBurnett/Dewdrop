#ifndef __DEWDROP_PROFILER_H
#define __DEWDROP_PROFILER_H
#include <cstdio>
#include <cstdarg>
#include <map>
#include <vector>
#include <chrono>
#include <fstream>
#include <thread> 

//Enable __PRETTY_FUNCTION__ to be used in microsoft environments
#ifdef _MSC_VER
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

constexpr bool _PROFILER_ENABLE_LOGGING = false;

#define _PROFILER_LOG(...){ printf(__VA_ARGS__); } //If you want to change the logging function, just change this line. 
#define _PROFILER_LOGFILE_NAME "Profile_Results_"

#define PROFILE_SAVE(){Profiler::Get()._SaveResults();}


#define PROFILE_START(name, tags){Profiler::Get()._StartProfile(name, __FUNCTION__, __PRETTY_FUNCTION__, __LINE__, __FILE__, std::this_thread::get_id());}
#define PROFILE_END(name){Profiler::Get()._EndProfile(name, std::this_thread::get_id());}


class Profiler {
public:
    static Profiler& Get();

    void _StartProfile(const char* name, const char* function, const char* signature, size_t line, const char* file, std::thread::id threadID);
    void _EndProfile(const char* name, std::thread::id threadID);
    void _SaveResults();

private:

    struct _ProfileData {
        std::chrono::time_point<std::chrono::steady_clock> startTime;
        std::chrono::time_point<std::chrono::steady_clock> endTime;
        std::chrono::nanoseconds duration_ns;
    };

    //Profiler();
    //Profiler(const Profiler&&) = delete;
    //Profiler(Profiler&) = delete;
    std::map<std::thread::id, std::map<std::string, std::chrono::time_point<std::chrono::steady_clock>>> m_Profiles;
    //std::map<std::thread::id, std::map<std::string, std::vector<std::chrono::nanoseconds>>> m_Data;
    std::map<std::thread::id, std::map<std::string, std::vector<
        _ProfileData>>> m_Data;

};



//FUNCTION DEFINITIONS

inline Profiler& Profiler::Get() {
    static Profiler instance;
    return instance;
}

inline void Profiler::_StartProfile(const char* name, const char* function, const char* signature, size_t line, const char* file, std::thread::id threadID)
{
    if (_PROFILER_ENABLE_LOGGING) {
        _PROFILER_LOG("Profiling [%s]\n\tFile %s\n\tFunction %s\n\tSignature %s\n\tLine %d\n\tThread ID %d\n", name, file, function, signature, line, threadID);
    }
    //Add to the map (thread -> function -> <data>)
    m_Profiles[threadID][name] = std::chrono::steady_clock::now();

}

inline void Profiler::_EndProfile(const char* name, std::thread::id threadID)
{
    const auto endTime = std::chrono::steady_clock::now();
    const auto time = endTime - m_Profiles[threadID][name];

    _ProfileData d = {};
    d.endTime = endTime;
    d.startTime = m_Profiles[threadID][name];
    d.duration_ns = time;

    m_Data[threadID][name].push_back(d);

    if (_PROFILER_ENABLE_LOGGING) {
        _PROFILER_LOG("Ending Profiling for %s [%d]\n\t%d nanoseconds\n", name, threadID, std::chrono::duration_cast<std::chrono::nanoseconds>(time).count());
    }
}

inline void Profiler::_SaveResults()
{
    printf("Profiler Save");

    std::fstream outFile;
    std::string fileName = (_PROFILER_LOGFILE_NAME);

    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);

    std::stringstream s;
    s << now.tm_year + 1900 << "-" << now.tm_mon + 1 << "-" << now.tm_mday << "-" << now.tm_hour << now.tm_min << now.tm_sec;
    fileName.append(s.str());

    fileName.append(".csv");

    outFile.open(fileName, std::ios::out | std::ios::app);


    outFile << "Thread ID, Name, Duration (ns), Start Time (ns), End Time (ns)\n";

    //Write the saved profile data 
    for (const auto& thread : m_Data) {
        const auto threadID = thread.first;

        for (const auto& profile : thread.second) {
            const auto name = profile.first;

            for (const auto& timePoint : profile.second) {
                const auto& startTime = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now() + std::chrono::duration_cast<std::chrono::system_clock::duration>(timePoint.startTime - std::chrono::steady_clock::now())
                );

                const auto& endTime = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now() + std::chrono::duration_cast<std::chrono::system_clock::duration>(timePoint.endTime - std::chrono::steady_clock::now())
                );

                const auto& duration = timePoint.duration_ns.count();

                struct tm profile_start_time;
                localtime_s(&profile_start_time, &t);

                struct tm profile_end_time;
                localtime_s(&profile_end_time, &t);



                outFile << threadID << ", " << name << ", " << duration << ", " << startTime << ", " << endTime << "\n";
            }
        }
    }

    outFile.close();
}
#endif
