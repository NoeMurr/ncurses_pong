/*******************************************************************************

                                    PONG
                              File: screen.c
*******************************************************************************/
#include "screen.h"

/* global screen variables */
int screen_width;
int screen_height;

/* static functions */
static void draw_racket(int racket){
  switch (racket) {
    case 1:
      mvwaddch(screen,racket_1.position.y - 1, racket_1.position.x, '#');
      mvwaddch(screen,racket_1.position.y, racket_1.position.x, '#');
      mvwaddch(screen,racket_1.position.y + 1, racket_1.position.x, '#');
      break;
    case 2:
      mvwaddch(screen,racket_2.position.y - 1, racket_2.position.x, '#');
      mvwaddch(screen,racket_2.position.y, racket_2.position.x, '#');
      mvwaddch(screen,racket_2.position.y + 1, racket_2.position.x, '#');
      break;
  }
}

static void draw_ball(){
  mvwaddch(screen, ball.position.y, ball.position.x, '*');
}

/* functions */
void init_screen(int height, int width){
  initscr(); /* ncurses init */

  cbreak();
  noecho();

  /* check arguments */
  screen_height = height < 20 ? 20 : height;
  screen_width = width < 80 ? 80 : width;

  /* windows */
  box_screen = newwin(screen_height+2, screen_width+2, 0, 0);
  screen = newwin(screen_height, screen_width, 1, 1);

  box(box_screen,0,0);

  /* hiding cursor */
  curs_set(0);
  keypad(stdscr, true);
  keypad(screen, true);

  refresh();
  wrefresh(box_screen);
  wrefresh(screen);
}

void * update_screen(void * args){
  while(1){

    wait_sec(0.2);
    wclear(screen);

    pthread_mutex_lock(&ball_handling);
    pthread_mutex_lock(&racket_1_handling);
    pthread_mutex_lock(&racket_2_handling);

    draw_racket(1);
    draw_racket(2);
    draw_ball();

    pthread_mutex_unlock(&racket_2_handling);
    pthread_mutex_unlock(&racket_1_handling);
    pthread_mutex_unlock(&ball_handling);

    wrefresh(screen);
  }
  return NULL;
}
