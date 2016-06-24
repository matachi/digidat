#include "port.h"
#include "keyboardML15.h"
#include "displayML15.h"

void main() {
    unsigned char c[6] = {0,0,0,0,0,0};
    unsigned char k;
    k = get_key();
    c[2] = k;
    //display_digits(c);
    display_dec(27835);
}
