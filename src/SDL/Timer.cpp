#include "Timer.h"

Timer::Timer()
{
    m_startTicks = 0;
    m_pausedTicks = 0;

    m_paused = false;
    m_started = false;
}

Timer::~Timer()
{
    //dtor
}

void Timer::start()
{
    m_started = true;

    m_paused = false;

    m_startTicks = 0;
    m_pausedTicks = 0;
}

void Timer::stop()
{
    m_started = false;
    m_paused = false;

    m_startTicks = 0;
    m_pausedTicks = 0;
}

void Timer::pause()
{
    if (m_started && !m_paused)
    {
        m_paused = true;

        m_pausedTicks = SDL_GetTicks() - m_startTicks;
        m_startTicks = 0;
    }
}

void Timer::unpause()
{
    if (m_started && m_paused)
    {
        m_paused = false;
        m_startTicks = SDL_GetTicks() - m_pausedTicks;

        m_pausedTicks = 0;
    }
}

Uint32 Timer::getTicks()
{
    Uint32 time = 0;

    if (m_started)
    {
        if (m_paused)
        {
            time = m_pausedTicks;
        }
        else
        {
            time = SDL_GetTicks() - m_startTicks;
        }
    }
    return time;
}


bool Timer::isStarted()
{
    return m_started;
}

bool Timer::isPaused()
{
    return m_paused && m_started;
}
