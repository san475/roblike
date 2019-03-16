#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "player.h"
#include "map.h"


//Structure Definitions

//Function Declarations
int screenSetUp();
int setUp(Player * user);
int mapSetUp();
int handle(int input, Player * user);
int checkPos(int dir, char tar, Player * user);
int printUI(Player* user);
