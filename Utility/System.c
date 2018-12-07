#include "Utility/System.h"

#if defined(SYSTEM_WINDOWS)
# include <windows.h>
#elif defined(SYSTEM_UNIX)
# include <unistd.h>
#endif

void sleepFor(int milliseconds) {

#if defined(SYSTEM_WINDOWS)
    Sleep(milliseconds);
#elif defined(SYSTEM_UNIX)
    usleep(1000 * milliseconds);
#endif

}

void shortSleep(void) {
    sleepFor(2000);
}
