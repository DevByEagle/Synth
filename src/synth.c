#include <stdio.h>
#include <stdlib.h>
#include "synth.h"

void quit(int status) {
    if (status != 0) {
        printf("Exiting with status %d\n", status);
    } else {
        return;
    }
    exit(status);
}