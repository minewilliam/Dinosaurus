#Gabriel Leblanc-Fontaine et William Longpré
#Makefile projet final

CC = g++
CFLAGS = -g -Wall
SRCS = src/main.cpp src/game2d.cpp src/terrain.cpp src/obstacle.cpp src/controller.cpp src/level.cpp src/player.cpp
PROG = dinosaurus

all: $(PROG)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS)

clean:
	-rm *.o
	-rm dinosaurus
