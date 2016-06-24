#include "clock.h"
#include "port.h"

static time_type clock;

void inthandler(void); // finns i assembler
void cli(void);

void init_clock(void) {
  clock = 0;
  IRQ_VEC = inthandler;
  CRGINT = 0x80;
  RTICTL = 0x10;
  cli();
}

void clock_inter(void) {
  set(CRGFLG, 0x80);
  ++clock;
}

time_type get_time(void) {
  return clock * 10;
}

void hold(time_type delay) {
  return; // TEEEEEEEEEEEEMPPPPPPPPPPPPPPPP
  //time_type end = delay + get_time();
  //while(end > get_time()) {};
}
