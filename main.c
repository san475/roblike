#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

//Structure Definitions
typedef struct Player
{
    int xPosition;
    int yPosition;
    int health;

} Player;

//Function Declarations
Player * playerSetUp();

int screenSetUp();
int mapSetUp();

//Main Function  
int main (void) 
{
    Player * user;
    screenSetUp();

    mapSetUp();

    user = playerSetUp();
    getch();

    endwin();

    return 0;
}


//Player Set Up
Player * playerSetUp()
{
    Player * newPlayer;
    newPlayer = malloc(sizeof(Player));

    newPlayer->xPosition = 14;
    newPlayer->yPosition = 14;
    newPlayer->health = 28;
    mvprintw(newPlayer->yPosition,newPlayer->xPosition, "@");

    return newPlayer;
}

//Screen clear Funct
int screenSetUp()
{
    initscr();
    printw("Hello World");
    noecho();
    refresh();

    return 0;
}

//Map Draw
int mapSetUp()
{
    mvprintw(13, 13, "--------");
    mvprintw(14, 13, "--------");
    mvprintw(15, 13, "--------");
    mvprintw(16, 13, "--------");
    mvprintw(17, 13, "--------");

}

