#include "port.h"

void main() {
    char c;
    c = ML4IN;
    c = c >> 1;
    ML4OUT = c;
}
