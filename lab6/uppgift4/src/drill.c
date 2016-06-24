#include "drill.h"
#include "port.h"
#include "clock.h"

port8 dSdw;

int getBit(int n, int k) {
    int mask, masked_n, thebit;
    mask =  1 << k;
    masked_n = n & mask;
    thebit = masked_n >> k;
    return thebit;
}

void init_drill(void) {
  DrillControl = 0;
  dSdw = 0;
}

void motorStart(void) {
  set(dSdw, 0x4);
  DrillControl = dSdw;
}

void motorStop(void) {
  clear(dSdw, 0x4);
  DrillControl = dSdw;
}

void drillDown(void) {
  set(dSdw, 0x8);
  DrillControl = dSdw;
}

void drillUp(void) {
  clear(dSdw, 0x8);
  DrillControl = dSdw;
}

int step(void) {
  if (getBit(DrillStatus, 1)) {
    set(dSdw, 0x1);
    set(dSdw, 0x2);
    DrillControl = dSdw;
    hold(500);
    clear(dSdw, 0x1);
    DrillControl = dSdw;
    return 1;
  } else {
    alarm(2);
    return 0;
  }
}

int nStep(int steps) {
  int counter = 0;
  int ans;
  while (counter < steps) {
    ++counter;
    ans = step();
    if (ans == 0) {
      return 0;
    }
  }
  return 1;
}

int drillDownTest(void) {
  int retries = 20;
  while (retries > 0) {
    if (getBit(DrillStatus, 2)) {
      return 1;
    }
    hold(250);
    --retries;
  }
  alarm(2);
  return 0;
}

void alarm(int signals) {
  if (signals == 0) {
r:  return;
  }
loop:  set(dSdw, 0x10);
  set(dSdw, 0x10);
  DrillControl = dSdw;
  hold(1000);
  clear(dSdw, 0x10);
  DrillControl = dSdw;
  --signals;
  if (signals == 0) {
    goto r;
  }
  hold(500);
  goto loop;
}

void drillHole(void) {
  int b;
  drillDown();
  b = drillDownTest();
  drillUp();
}

int refPos(void) {
  int x;
loop:  if (getBit(DrillStatus, 0)) {
    return 1;
  }
  x = step();
  if (!x) {
    return 0;
  }
  goto loop;
}

void doAuto(void) {
  char spaces[] = {0,1,1,1,1,1,1,1,2,1,5,2,2,2,2,4,4,3,8,2,99};
  char *p = &spaces[0];
  if(!refPos()) {
    motorStop();
    return;
  }
  motorStart();
  while (*p != 99) {
    if(!nStep(*p)) {
      motorStop();
      return;
    }
    drillHole();
    ++p;
  }
  motorStop();
}
