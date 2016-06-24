#include "keyboardML15.h"

unsigned char get_key() {
  unsigned char c, e=0;
  while (1) {
    c = ML4IN;
    e = c >> 7;
    if (e == 0) {
      break;
    }
  }
  return c;
}
