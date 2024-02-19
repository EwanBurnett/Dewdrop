#ifndef __DEWDROP_TIMER_H
#define __DEWDROP_TIMER_H

#include <chrono>

namespace Dewdrop {
    class Timer {
    public:
        Timer(); 

        template<typename period = std::chrono::seconds, typename resolution = std::chrono::nanoseconds>
        double DeltaTime() const;

        void Tick(); 
        void Start(); 
        void Reset(); 
    private:
        std::chrono::high_resolution_clock::time_point m_tPrevious;
        std::chrono::high_resolution_clock::time_point m_tCurrent;
    };


    template<typename period, typename resolution>
    inline double Dewdrop::Timer::DeltaTime() const
    {
        static_assert(std::chrono::_Is_duration_v<period>, "Must be a std::chrono::duration!\n");
        static_assert(std::chrono::_Is_duration_v<resolution>, "Must be a std::chrono::duration!\n");

        //Compute a divisor based on our period
        auto d = std::ratio_divide<resolution::period, period::period>::den;
        double count = std::chrono::duration_cast<resolution>(m_tCurrent - m_tPrevious).count() / (double)d;

        return count;
    }
}

#endif