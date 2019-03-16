/*
   Header file for map file
   room struct definition
   Create map: will create rooms in scope
    - Create room helper function
   Print map: will print all rooms out
   */
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

typedef struct Room
{
    int yPosition;
    int xPosition;

    int height;
    int width;
} Room;

Room * createRoom(int y, int x, int height, int width);
Room ** createMap();
int drawRoom(Room * room);
