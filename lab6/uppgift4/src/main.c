#include "port.h"
#include "keyboardML15.h"
#include "displayML15.h"
#include "clock.h"
#include "drill.h"

void main() {
    unsigned char k;
    init_clock();
    init_drill();
loop: k = get_key();
    switch (k) {
      case 0:
        motorStart();
	break;
      case 1:
        motorStop();
	break;
      case 2:
        drillDown();
	break;
      case 3:
        drillUp();
	break;
      case 4:
        step();
	break;
      case 5:
        drillHole();
	break;
      case 6:
        refPos();
	break;
      case 7:
        doAuto();
	break;
    }
    goto loop;
}
