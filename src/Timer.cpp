#include "../include/Dewdrop/Timer.h"

Dewdrop::Timer::Timer() {
    m_tCurrent = {};
    m_tPrevious = {};
}

void Dewdrop::Timer::Tick()
{
    m_tPrevious = m_tCurrent; 
    m_tCurrent = std::chrono::high_resolution_clock::now(); 
}

void Dewdrop::Timer::Start()
{
}

void Dewdrop::Timer::Reset()
{
}
