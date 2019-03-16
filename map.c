/*
   File for setting up the map
   Will create room structures randomly and smartly, keep them in array
   Print them to Map on call from main
   */

#include "map.h"

#define MAX_ROOMS 3

Room * createRoom(int y, int x, int height, int width)
{
    Room * new_room;
    new_room = malloc(sizeof(new_room));
    new_room->yPosition = y;
    new_room->xPosition = x;
    new_room->height = height;
    new_room->width = width;

    return new_room;
}

Room ** createMap()
{
    Room ** map;
    map = malloc(sizeof(Room) * MAX_ROOMS);

    Room ** mapi = map;

    *mapi = createRoom(12, 13, 10, 14);
    drawRoom(*mapi);
    mapi++;
    *mapi = createRoom(10, 35, 4, 6);
    drawRoom(*mapi);
    mapi++;
    *mapi = createRoom(2, 2, 5, 5);
    drawRoom(*mapi);

    return map;
}

int drawRoom(Room * room)
{
    int x, y;
    for(x = room->xPosition; x < room->xPosition + room->width; x++)
    {
        mvprintw(room->yPosition, x, "-");
        mvprintw(room->yPosition + room->height - 1, x, "-");

    }

    for(y = room->yPosition + 1; y < room->yPosition + room->height - 1; y++)
    {
        mvprintw(y, room->xPosition, "|");
        for(int i = room->xPosition + 1; i < room->xPosition + room->width - 1; i++)
        {
            mvprintw(y, i, ".");
        }
        mvprintw(y, room->xPosition + room->width - 1, "|");

    }
    return 0;
}
