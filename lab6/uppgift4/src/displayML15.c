#include "port.h"
#include "displayML15.h"

void display_digits(unsigned char *c) {
  char counter = 0;
  ML4OUT = 1;
  ML4OUT2 = 0xD0;
  ML4OUT = 0;
  while (counter < 6) {
    ML4OUT2 = *c;
    counter += 1;
    ++c;
  }
  ML4OUT2 = 0;
  ML4OUT2 = 0;
}

void display_dec(unsigned int i) {
  char counter = 5;
  unsigned int div = 1;
  unsigned char c[6] = {0,0,0,0,0,0};
  while (counter >= 0) {
    c[counter] = (i / div) % 10;
    div *= 10;
    --counter;
  }
  display_digits(c);
}
