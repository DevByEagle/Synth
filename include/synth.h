#ifndef SYNTH_H
#define SYNTH_H

#include "types.h"

namespace Synth {
  void SYNTH_API delay(size_t secends);
  void SYNTH_API println(const char* format, ...);
}

#endif //SYNTH_H
