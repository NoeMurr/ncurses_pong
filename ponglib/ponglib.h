/*******************************************************************************

                                    PONG
                              File: globals.h
*******************************************************************************/
#ifndef PONGLIB_H
#define PONGLIB_H

#include <pthread.h>
#include <stdio.h> /* perror() */
#include <time.h> /* sleep() */
#include <ncurses.h>

/* types */
typedef enum ball_direction ball_direction_t;
typedef enum racket_direction racket_direction_t;
typedef struct position position_t;
typedef struct racket racket_t;
typedef struct ball ball_t;

/* game variables */
ball_t ball;
racket_t racket_1;
racket_t racket_2;

/* thread variables */
pthread_mutex_t ball_handling;
pthread_mutex_t racket_1_handling;
pthread_mutex_t racket_2_handling;

/* screen globals variables */
int screen_width;
int screen_height;
WINDOW * box_screen;
WINDOW * screen;

/* structures and enums */
enum ball_direction {
  NE=1,
  E=2,
  SE=3,
  SW=4,
  W=5,
  NW=6
};

enum racket_direction {
  N=1,
  S=2
};

struct position{
  int x;
  int y;
};

struct ball{
  ball_direction_t direction; /* from 1 to 6 */
  char simbol;
  position_t position;
};

struct racket{
  racket_direction_t direction;
  position_t position;
};

/* functions */
void wait_sec(float seconds); /* wait function */

#endif /* PONGLIB_H */
