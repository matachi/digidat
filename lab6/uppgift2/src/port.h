typedef unsigned char port8;
typedef unsigned short port16;
typedef unsigned long port32;
typedef port8 *port8ptr;

#define ML4IN_ADDRESS 0x9C0
#define ML4IN *((port8ptr) ML4IN_ADDRESS)
#define ML4OUT_ADDRESS 0x9C2
#define ML4OUT *((port8ptr) ML4OUT_ADDRESS)
#define ML4OUT2_ADDRESS 0x9C3
#define ML4OUT2 *((port8ptr) ML4OUT2_ADDRESS)

#define set(x, mask) (x) = (x) | (mask)
#define clear(x, mask) (x) = (x) & ~(mask)
