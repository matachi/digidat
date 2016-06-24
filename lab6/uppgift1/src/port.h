typedef unsigned char port8;
typedef unsigned short port16;
typedef unsigned long port32;
typedef port8 *port8ptr;

#define ML4OUT_ADDRESS 0x400
#define ML4OUT *((port8ptr) ML4OUT_ADDRESS)
#define ML4IN_ADDRESS 0x600
#define ML4IN *((port8ptr) ML4IN_ADDRESS)

#define set(x, mask) (x) = (x) | (mask)
#define clear(x, mask) (x) = (x) & ~(mask)
