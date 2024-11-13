#pragma once

#ifdef EXPORTS
    #define SYNTH_API __declspec(dllexport)
#else
    #define SYNTH_API __declspec(dllimport)
#endif

namespace Synth {
    typedef unsigned int size_t; 
}
