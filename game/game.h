/*******************************************************************************

                                    PONG
                              File: game.h
*******************************************************************************/
#ifndef GAME_H
#define GAME_H
#include "../ponglib/ponglib.h"
#include <stdlib.h> /* random functions */

/* initialize function */
void init_game(void); /* initialize the position of rackets and ball */

/* game functions */
void * move_ball(void * args); /* change bals position and direction */

void * move_racket(void * racket); /* will move the racket passed as arg. */


#endif /* GAME_H */
