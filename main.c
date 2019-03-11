#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "main.h"


//Main Function  
int main (void) 
{
    //init player pointer
    Player * user;

    //define player pointer
    user = playerSetUp();

    //clear screen and set up option
    screenSetUp();

    //init input char int
    int ch;

    //draw rooms
    mapSetUp();

    //set up player and ui
    setUp(user);
   


//Main game loop
    while((ch = getch()) != 'y')
    {
        handle(ch, user);
        setUp(user);
    }

    endwin();
    free(user);
    return 0;
}


//Screen clear Funct
int screenSetUp()
{
    initscr();
    noecho();
    refresh();

    return 0;
}
/*
 * sets up player and ui based on player
 * */
int setUp(Player * user)
{
    printPlayer(user);
    printUI(user);

    return 0;
}

//Map Draw
int mapSetUp()
{
    mvprintw(12, 13, "----------------");
    mvprintw(13, 13, "|..............|");
    mvprintw(14, 13, "|..............|");
    mvprintw(15, 13, "|..............|");
    mvprintw(16, 13, "|..............|");
    mvprintw(17, 13, "|..............|");
    mvprintw(18, 13, "----------------");
    return 0;
}


int handle(int input, Player * user)
{
    switch(input)
    {
        //UP
        case 'k':
        case 'K':
            if(checkPos(0, '-', user) != 1)
                movePlayer(user->yPosition-1, user->xPosition, user);
            break;
            
        //LEFT
        case 'h':
        case 'H':
            if(checkPos(3, '|', user) != 1)
                movePlayer(user->yPosition, user->xPosition-1, user);
            break;
        //RIGHT
        case 'l':
        case 'L':
            if(checkPos(1, '|', user) != 1)
                movePlayer(user->yPosition, user->xPosition+1, user);
            break;
        //DOWN
        case 'j':
        case 'J':
            if(checkPos(2, '-', user) != 1)
                movePlayer(user->yPosition+1, user->xPosition, user);
            break;

        default:
            break;
    }
    return 0;
}

//Put in direction, 0 is up, going clockwise, 1 is right, etc. 'target', and the Player, and will return 1 if the target is found
int checkPos(int dir, char tar, Player * user)
{
    int returning = 0;
    if(dir == 0)
    {
        if(mvinch(user->yPosition - 1, user->xPosition) == tar)
            returning = 1;
    }
    else if(dir == 1)
    {
        if(mvinch(user->yPosition, user->xPosition + 1) == tar)
            returning = 1;
    }
    else if(dir == 2)
    {
        if(mvinch(user->yPosition + 1, user->xPosition) == tar)
            returning = 1;
    }
    else if(dir == 3)
    {
        if(mvinch(user->yPosition, user->xPosition - 1) == tar)
            returning = 1;
    }

    move(user->yPosition, user->xPosition);

    return returning;
} 

//moves player to new position
int printUI(Player *user)
{
    /*
    char* health = malloc(sizeof(int) * 5);
    char* x = malloc(sizeof(int) * 5);
    char* y = malloc(sizeof(int) * 5);
    
    sprintf( health, "HP: %d", user -> health);
    sprintf( x, "x: %d", user -> xPosition);
    sprintf( y, "y: %d", user -> yPosition);
    */
    //changed to user ->
    mvprintw(22, 14, "HP: %d", user->health);
    mvprintw(22, 28, "y: %d", user->yPosition);
    mvprintw(22, 22, "x: %d", user->xPosition);
    // Moves back curor to player
    move(user->yPosition, user->xPosition);

    return 0;
}
