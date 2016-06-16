CC=Clang
CFLAGS=-O3 -Wall
GAME_DIR=game
PONGLIB_DIR=ponglib
SCREEN_DIR=screen
OBJ= $(GAME_DIR)/game.o $(PONGLIB_DIR)/ponglib.o $(SCREEN_DIR)/screen.o main.o
BIN=pong
LFLAGS= -lncurses -lpthread

$(BIN) : $(OBJ)
	$(CC) -o $@ $? $(LFLAGS) $(CFLAGS) -g

$(GAME_DIR)/game.o : $(GAME_DIR)/game.c
	$(CC) -o $@ -c $? $(CFLAGS) -g

$(PONGLIB_DIR)/ponglib.o : $(PONGLIB_DIR)/ponglib.c
	$(CC) -o $@ -c $? $(CFLAGS) -g

$(SCREEN_DIR)/screen.o : $(SCREEN_DIR)/screen.c
	$(CC) -o $@ -c $? $(CFLAGS) -g

main.o : main.c
	$(CC) -o $@ -c $? $(CFLAGS) -g

clean :
	rm $(GAME_DIR)/*.o
	rm $(SCREEN_DIR)/*.o
	rm $(PONGLIB_DIR)/*.o
	rm *.o
