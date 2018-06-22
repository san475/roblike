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


int screenSetUp();
int mapSetUp();
Player * playerSetUp();
int handle(int input, Player * user);
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
    newPlayer->yPosition = 10;
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
    mvprintw(12, 13, "---------");
    mvprintw(13, 13, "|.......|");
    mvprintw(14, 13, "|.......|");
    mvprintw(15, 13, "|.......|");
    mvprintw(16, 13, "|.......|");
    mvprintw(17, 13, "|.......|");
    mvprintw(18, 13, "---------");
}

int handle(int input,Player * user){

    
    switch(input)
    {
        //UP
        case 'w':
        case 'W':
            if(mvinch(user->yPosition-1, user->xPosition) != '-')
                printPlayer(user->yPosition-1, user->xPosition, user);
            move(user->yPosition, user->xPosition);
            break;
            //LEFT
        case 'a':
        case 'A':
            if(mvinch(user->yPosition, user->xPosition - 1) != '|')
                printPlayer(user->yPosition, user->xPosition-1, user);
            move(user->yPosition, user->xPosition);
            break;
            //RIGHT
        case 'd':
        case 'D':
            if(mvinch(user->yPosition, user->xPosition + 1) != '|')
                printPlayer(user->yPosition, user->xPosition+1, user);
            move(user->yPosition, user->xPosition);
            break;
            //DOWN
        case 's':
        case 'S':
            if(mvinch(user->yPosition+1, user->xPosition) != '-')
                printPlayer(user->yPosition+1, user->xPosition, user);
            move(user->yPosition, user->xPosition);
            break;

        default:
            break;

    }
    return 0;
}


int printPlayer(int y, int x, Player * userMove){

    mvprintw(userMove->yPosition, userMove->xPosition, ".");
    userMove->xPosition = x;
    userMove->yPosition = y;

    mvprintw(userMove->yPosition, userMove->xPosition, "@");
    move(userMove->yPosition, userMove->xPosition);

    return 0;
}
