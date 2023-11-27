#ifndef
#include "Food.h"
#include "MacUILib.h"
#include <cstdlib> //provides srand() and rand()
#include <time.h> //provides time

Food::Food()
{
    foodPos.setObjPos(-1, -1, 'o'); //intalize foodpos outside of the game board
    

}


Food::~Food(){}


void Food::generateFood(objPos blockOff)
{
    //generate random x and y coord, and make sure they are not boarder or blockOff pos

    //check x and y against 0 and boardSizeX/Y

    //rmber in objPos class you have an isPosEqual() method
    
}

void Food::getFoodPos(&returnPos)
{
    
}

