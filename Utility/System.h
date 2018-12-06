#pragma once

#if defined(_WIN32)
# define SYSTEM_WINDOWS
#elif defined(__unix__)
# define SYSTEM_UNIX
#endif

void sleepFor(int milliseconds);
void shortSleep();
