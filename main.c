#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

//Structure Definitions
typedef struct Player
{
    int xPosition;
    int yPosition;
    int health;

} Player;

//Function Declarations
int screenSetUp();
int mapSetUp();
Player * playerSetUp();
int handle(int input, Player * user);
int checkPos(int dir, char tar, Player * user);
int printPlayer(int y, int x, Player * userMove);

//Main Function  
int main (void) 
{
    Player * user;
    screenSetUp();
    int ch;
    mapSetUp();

    user = playerSetUp();

//Main game loop
    while((ch = getch()) != 'y')
    {
        handle(ch,user);

    }

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
    move(newPlayer->yPosition, newPlayer->xPosition);

    return newPlayer;
}

//Screen clear Funct
int screenSetUp()
{
    initscr();
    noecho();
    refresh();

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
}

int handle(int input,Player * user){
    switch(input)
    {
        //UP
        case 'w':
        case 'W':
            if(checkPos(0, '-', user) != 1)
                printPlayer(user->yPosition-1, user->xPosition, user);
            break;
            
        //LEFT
        case 'a':
        case 'A':
            if(checkPos(3, '|', user) != 1)
                printPlayer(user->yPosition, user->xPosition-1, user);
            break;
        //RIGHT
        case 'd':
        case 'D':
            if(checkPos(1, '|', user) != 1)
                printPlayer(user->yPosition, user->xPosition+1, user);
            break;
        //DOWN
        case 's':
        case 'S':
            if(checkPos(2, '-', user) != 1)
                printPlayer(user->yPosition+1, user->xPosition, user);
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
int printPlayer(int y, int x, Player * userMove){

    mvprintw(userMove->yPosition, userMove->xPosition, ".");
    userMove->xPosition = x;
    userMove->yPosition = y;

    mvprintw(userMove->yPosition, userMove->xPosition, "@");
    move(userMove->yPosition, userMove->xPosition);

    return 0;
}
