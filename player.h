#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

//Header file for Player
//
//Player struct def
typedef struct Player
{
    int xPosition;
    int yPosition;
    int health;

} Player;

//Sets up player struct
Player * playerSetUp();
//Ncurses print player
int movePlayer(int y, int x, Player * userMove);
int printPlayer(Player * user);
//Updates player struct
int updatePlayer(int input, Player *user);
