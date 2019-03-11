#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "player.h"


// Player Set Up
Player * playerSetUp()
{
    // Allocates memory for Player
    Player * newPlayer;
    newPlayer = malloc(sizeof(Player));

    // Sets values
    newPlayer->xPosition = 14;
    newPlayer->yPosition = 14;
    newPlayer->health = 28;

    // Prints player
    mvprintw(newPlayer->yPosition,newPlayer->xPosition, "@");
    move(newPlayer->yPosition, newPlayer->xPosition);

    // Returns pointer
    return newPlayer;
}
// move player to new y, x, and add a . at prev location
int movePlayer(int y, int x, Player * userMove)
{

    mvprintw(userMove->yPosition, userMove->xPosition, ".");
    userMove->xPosition = x;
    userMove->yPosition = y;

    mvprintw(userMove->yPosition, userMove->xPosition, "@");
    move(userMove->yPosition, userMove->xPosition);

    return 0;
}
// Print player at current y, x
int printPlayer(Player * user)
{
    mvprintw(user->yPosition, user->xPosition, "@");
    move(user->yPosition, user->xPosition);
    return 0;
}
