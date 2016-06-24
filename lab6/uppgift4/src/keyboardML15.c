#include "keyboardML15.h"

unsigned char get_key() {
  unsigned char c, d, e=0;
  while (1) {
    c = ML4IN;
    e = c >> 7;
    if (e == 0) {
      break;
    }
  }
  while (1) {
    d = ML4IN;
    e = d >> 7;
    if (e == 1) {
      break;
    }
  }
  return c;
}
