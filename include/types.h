#pragma once

#if defined(_WIN32)
    #ifdef EXPORTS
        #define SYNAPI __declspec(dllexport)
    #else
        #define SYNAPI __declspec(dllimport)
    #endif
#elif defined(__linux__) || defined(__APPLE__)
    #define SYNAPI __attribute__((visibility("default")))
#else
    #error "Synth is not supported"
#endif

namespace Synth {
    
}