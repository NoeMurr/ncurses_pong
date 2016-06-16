/*******************************************************************************

                                    PONG
                              File: ponglib.c
*******************************************************************************/
#include "ponglib.h"

/* functions */
void wait_sec(float seconds){
  struct timespec time1, time2;
  time1.tv_sec = (int)seconds;
  time1.tv_nsec = (seconds - (int)seconds) * 1e8;

  if (nanosleep(&time1, &time2) < 0) {
    fprintf(stderr, "error in wait function");
  }
}
