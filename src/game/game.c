/*******************************************************************************

                                    PONG
                              File: game.c
*******************************************************************************/
#include "game.h"


/* functions */
void init_game(void){
  /* positioning rackets and ball */
  /* NB the coordinates of the objects are relative to screen window */
  ball.position.y = screen_height/2;
  ball.position.x = screen_width/2;

  racket_1.position.y = screen_height/2;
  racket_1.position.x = 1;

  racket_2.position.y = screen_height/2; /* down right corner */
  racket_2.position.x = screen_width-2;

  /* initializing ball direction */
  srand(time(NULL));
  ball.direction = (rand() % 6) +1;
}


void * move_ball(void * args){
  while (1) {
    wait_sec(0.5);
    pthread_mutex_lock(&ball_handling);
    switch (ball.direction) {
      case NE:
        if (ball.position.y-1 > 0 && ball.position.x+1 < screen_width-2) {
          ball.position.y -= 1;
          ball.position.x += 1;
        }
        else if(ball.position.y-1 == 0){
          ball.position.y -= 1;
          ball.position.x += 1;
          ball.direction = SE;
        }
        else if(ball.position.x+1 == screen_width-2){

          /* checking racket position */
          pthread_mutex_lock(&racket_2_handling);
          if (racket_2.position.y+1 == ball.position.y-1) {
            ball.direction = (rand() % 2) + 5;
            ball.position.y -= 1;
            ball.position.x +=1;
          }
          else if (racket_2.position.y == ball.position.y-1) {
            ball.direction = (rand() % 2) + 5;
            ball.position.y -= 1;
            ball.position.x +=1;
          }
          else if (racket_2.position.y-1 == ball.position.y-1) {
            ball.direction = (rand() % 2) + 5;
            ball.position.y -= 1;
            ball.position.x +=1;
          }
          else{
            ball.position.y -= 1;
            ball.position.x += 1;
          }
          pthread_mutex_unlock(&racket_2_handling);
        }
        else if (ball.position.x+1 == screen_width-1) {
          ball.position.y = screen_height/2;
          ball.position.x = screen_width/2;
          ball.direction = (rand() % 6) +1;
        }
        break;
      case E:
        if (ball.position.x+1 < screen_width - 2) {
          ball.position.x += 1;
        }
        else if(ball.position.x+1 == screen_width-2){
          /* checking racket position */
          pthread_mutex_lock(&racket_2_handling);
          if (racket_2.position.y+1 == ball.position.y) {
            ball.direction = (rand() % 3) + 4;
            ball.position.x +=1;
          }
          else if (racket_2.position.y == ball.position.y) {
            ball.direction = (rand() % 3) + 4;
            ball.position.x +=1;
          }
          else if (racket_2.position.y-1 == ball.position.y) {
            ball.direction = (rand() % 3) + 4;
            ball.position.x +=1;
          }
          else {
            ball.position.x += 1;
          }
          pthread_mutex_unlock(&racket_2_handling);
        }
        else if (ball.position.x+1 == screen_width-1){
          ball.position.y = screen_height/2;
          ball.position.x = screen_width/2;
          ball.direction = (rand() % 6) +1;
        }
        break;
      case SE:
        if (ball.position.y+1 < screen_height-1 &&
            ball.position.x+1 < screen_width - 2) {
          ball.position.y += 1;
          ball.position.x += 1;
        }
        else if (ball.position.y+1 == screen_height-1) {
          ball.position.y += 1;
          ball.position.x += 1;
          ball.direction = NE;
        }
        else if(ball.position.x+1 == screen_width-2){
          /* checking racket position */
          pthread_mutex_lock(&racket_2_handling);
          if (racket_2.position.y+1 == ball.position.y+1) {
            ball.direction = (rand() % 2) + 4;
            ball.position.y +=1;
            ball.position.x +=1;
          }
          else if (racket_2.position.y == ball.position.y+1) {
            ball.direction = (rand() % 2) + 4;
            ball.position.y +=1;
            ball.position.x +=1;
          }
          else if (racket_2.position.y-1 == ball.position.y+1) {
            ball.direction = (rand() % 2) + 4;
            ball.position.y +=1;
            ball.position.x +=1;
          }
          else{
            ball.position.y +=1;
            ball.position.x += 1;
          }
          pthread_mutex_unlock(&racket_2_handling);
        }
        else if (ball.position.x+1 == screen_width-1) {
          ball.position.y = screen_height/2;
          ball.position.x = screen_width/2;
          ball.direction = (rand() % 6) +1;
        }
        break;
      case NW: /* North West */
        if (ball.position.y-1 > 0 && ball.position.x-1 > 1) {
          ball.position.y -= 1;
          ball.position.x -= 1;
        }
        else if(ball.position.y-1 == 0){
          ball.position.y -= 1;
          ball.position.x -= 1;
          ball.direction = SW;
        }
        else if(ball.position.x-1 == 1){

          /* checking racket position */
          pthread_mutex_lock(&racket_1_handling);
          if (racket_1.position.y+1 == ball.position.y-1) {
            ball.direction = (rand() % 2) + 1;
            ball.position.y -= 1;
            ball.position.x -=1;
          }
          else if (racket_1.position.y == ball.position.y-1) {
            ball.direction = (rand() % 2) + 1;
            ball.position.y -= 1;
            ball.position.x -=1;
          }
          else if (racket_1.position.y-1 == ball.position.y-1) {
            ball.direction = (rand() % 2) + 1;
            ball.position.y -= 1;
            ball.position.x -=1;
          }
          else{
            ball.position.y -= 1;
            ball.position.x -= 1;
          }
          pthread_mutex_unlock(&racket_1_handling);
        }
        else if (ball.position.x-1 == 0) {
          ball.position.y = screen_height/2;
          ball.position.x = screen_width/2;
          ball.direction = (rand() % 6) +1;
        }
        break;
      case W:
        if (ball.position.x-1 > 1) {
          ball.position.x -= 1;
        }
        else if(ball.position.x-1 == 1){

          /* checking racket position */
          pthread_mutex_lock(&racket_1_handling);
          if (racket_1.position.y+1 == ball.position.y) {
            ball.direction = (rand() % 3) + 1;
            ball.position.x -=1;
          }
          else if (racket_1.position.y == ball.position.y) {
            ball.direction = (rand() % 3) + 1;
            ball.position.x -=1;
          }
          else if (racket_1.position.y-1 == ball.position.y) {
            ball.direction = (rand() % 3) + 1;
            ball.position.x -=1;
          }
          else{
            ball.position.x -= 1;
          }
          pthread_mutex_unlock(&racket_1_handling);
        }
        else if (ball.position.x-1 == 0) {
          ball.position.y = screen_height/2;
          ball.position.x = screen_width/2;
          ball.direction = (rand() % 6) +1;
        }
        break;
      case SW:
        if (ball.position.y+1 < screen_height-1
          && ball.position.x-1 > 1) {
          ball.position.y += 1;
          ball.position.x -= 1;
        }
        else if(ball.position.y+1 == screen_height-1){
          ball.position.y += 1;
          ball.position.x -= 1;
          ball.direction = NW;
        }
        else if(ball.position.x-1 == 1){

          /* checking racket position */
          pthread_mutex_lock(&racket_1_handling);
          if (racket_1.position.y+1 == ball.position.y+1) {
            ball.direction = (rand() % 2) + 2;
            ball.position.y += 1;
            ball.position.x -=1;
          }
          else if (racket_1.position.y == ball.position.y+1) {
            ball.direction = (rand() % 2) + 2;
            ball.position.y += 1;
            ball.position.x -=1;
          }
          else if (racket_1.position.y-1 == ball.position.y+1) {
            ball.direction = (rand() % 2) + 2;
            ball.position.y += 1;
            ball.position.x -=1;
          }
          else{
            ball.position.y += 1;
            ball.position.x -= 1;
          }
          pthread_mutex_unlock(&racket_1_handling);
        }
        else if (ball.position.x-1 == 0) {
          ball.position.y = screen_height/2;
          ball.position.x = screen_width/2;
          ball.direction = (rand() % 6) +1;
        }
        break;
    }
    pthread_mutex_unlock(&ball_handling);
  }
  return NULL;
}

void * move_racket(void * racket){
  int controll;
  while (1) {
    controll = getch();
    switch (controll) {
      case 'w':
        pthread_mutex_lock(&racket_1_handling);
        if(racket_1.position.y > 2){
          racket_1.position.y -=1;
        }
        pthread_mutex_unlock(&racket_1_handling);
        break;
      case 's':
        pthread_mutex_lock(&racket_1_handling);
        if(racket_1.position.y < screen_height-2){
          racket_1.position.y +=1;
        }
        pthread_mutex_unlock(&racket_1_handling);
        break;
      case 'd':
        pthread_mutex_lock(&racket_1_handling);
        if(racket_1.position.y < screen_height-4){
          racket_1.position.y +=2;
        }
        else if(racket_1.position.y < screen_height-2){
          racket_1.position.y +=1;
        }
        pthread_mutex_unlock(&racket_1_handling);
        break;
      case 'a':
        pthread_mutex_lock(&racket_1_handling);
        if(racket_1.position.y > 4){
          racket_1.position.y -=2;
        }
        else if(racket_1.position.y > 2){
          racket_1.position.y -=1;
        }
        pthread_mutex_unlock(&racket_1_handling);
        break;
      case KEY_UP:
        pthread_mutex_lock(&racket_2_handling);
        if(racket_2.position.y > 2){
          racket_2.position.y -=1;
        }
        pthread_mutex_unlock(&racket_2_handling);
        break;
      case KEY_DOWN:
        pthread_mutex_lock(&racket_2_handling);
        if(racket_2.position.y < screen_height-2){
          racket_2.position.y +=1;
        }
        pthread_mutex_unlock(&racket_2_handling);
        break;
      case KEY_LEFT:
        pthread_mutex_lock(&racket_2_handling);
        if(racket_2.position.y > 4){
          racket_2.position.y -=2;
        }
        else if(racket_2.position.y > 2){
          racket_2.position.y -=1;
        }
        pthread_mutex_unlock(&racket_2_handling);
        break;
      case KEY_RIGHT:
        pthread_mutex_lock(&racket_2_handling);
        if(racket_2.position.y < screen_height-4){
          racket_2.position.y +=2;
        }
        else if(racket_2.position.y < screen_height-2){
          racket_2.position.y +=1;
        }
        pthread_mutex_unlock(&racket_2_handling);
        break;
    }
  }

  return NULL;
}
