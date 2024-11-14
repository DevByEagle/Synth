#include <cstdio>
#include <cstdarg>
#include <unistd.h>

#include "../include/synth.h"

namespace Synth {
   void delay(size_t secends) {
        sleep(secends);
   }

  void println(const char* format, ...) {
    std::va_list args;
    va_start(args, format);

    std::vprintf(format, args);
    
    va_end(args);
  }
}
