/*******************************************************************************

                                    PONG
                              File: main.c
*******************************************************************************/
#include <stdio.h>
#include "screen/screen.h"
#include "game/game.h"

int main(int argc, char const *argv[]) {
  init_screen(30,75);
  init_game();
  pthread_t screen_updater;
  pthread_t ball_worker;
  pthread_t racket_controller;
  pthread_create(&racket_controller,NULL,&move_racket,NULL);
  pthread_create(&ball_worker,NULL,&move_ball,NULL);
  pthread_create(&screen_updater,NULL,&update_screen,NULL);
  pthread_join(racket_controller, (void *)10);
  endwin();
  return 0;
}
