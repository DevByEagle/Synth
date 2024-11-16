#include "synth.h"

string getdevice()
{
#if defined(_WIN32) || defined(_WIN64)
    return "Windows";
#elif defined(__APPLE__)
    return "MacOS"
#elif defined(__linux__)
    return "Linux"
#else
#error "Synth dose not support your device";
#endif
}
