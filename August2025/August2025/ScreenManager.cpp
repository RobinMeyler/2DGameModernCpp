#include "ScreenManager.h"

// Class will need Mutexes if Threaded
ScreenManager& ScreenManager::getInstance()
{
    // Created once and threadsafe (C++11)
    static ScreenManager instance;
    return instance;
}

void ScreenManager::setDimensions(int t_width, int t_height)
{
    m_width = t_width;
    m_height = t_height;
}