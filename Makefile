CC = gcc
CFLAGS = -g -Wall
LIBS = -lncurses

default: main

main: bagfunc.o cetromino_functions.o color_management.o grid.o time_manage.o main.o
	$(CC) $(CFLAGS) bagfunc.o cetromino_functions.o color_management.o grid.o time_manage.o main.o -o main.exe $(LIBS)

bagfunc.o: bagfunc.c gamedefinitions.h
	$(CC) $(CFLAGS) -c bagfunc.c

cetromino_functions.o: cetromino_functions.c cetrominobase.h
	$(CC) $(CFLAGS) -c cetromino_functions.c

color_management.o: color_management.c
	$(CC) $(CFLAGS) -c color_management.c

grid.o: grid.c gamedefinitions.h color_management.h
	$(CC) $(CFLAGS) -c grid.c

time_manage.o: time_manage.c 
	$(CC) $(CFLAGS) -c time_manage.c

main.o: main.c cetrominobase.h cetromino_functions.h grid.h gamedefinitions.h bagfunc.h time_manage.h color_management.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm bagfunc.o cetromino_functions.o color_management.o grid.o main.o time_manage.o