#include "port.h"
#include "keyboardML15.h"
#include "displayML15.h"
#include "clock.h"

void main() {
    //unsigned char c[6] = {0,0,0,0,0,0};
    //unsigned char k;
    //k = get_key();
    //c[2] = k;
    //display_digits(c);
    while(1) {
      display_dec(get_time());
    }
}

//void inthandler(void) {
//	i++;
//}
