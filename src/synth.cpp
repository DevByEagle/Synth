#include <unistd.h>

#include "../include/synth.h"

namespace Synth {
    void delay(size_t secends) {
        sleep(secends);
    }
}
