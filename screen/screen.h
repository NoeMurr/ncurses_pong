/*******************************************************************************

                                    PONG
                              File: screen.h
*******************************************************************************/
#ifndef SCREEN_H
#define SCREEN_H
#include "../ponglib/ponglib.h"
#include <stdlib.h> /* random */


/* game constants */
#define BALL '*'


/* screen variables */
extern int screen_width;
extern int screen_height;

/* screen functions */
void init_screen(int height, int width);/* this will initialize the screen and
                                          will put the rackets and the ball on
                                          the screen */

void * update_screen(void * args); /* will update the screen every 0.2 seconds */


#endif /* SCREEN_H */
