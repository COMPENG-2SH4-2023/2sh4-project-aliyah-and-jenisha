
#include "Food.h"
//#include "MacUILib.h"
//#include <cstdlib> //provides srand() and rand()
//#include <time.h> //provides time

Food::Food()
{
    foodPos.setObjPos(-1, -1, 'o'); //intalize foodpos outside of the game board
    

}


Food::~Food(){}


void Food::generateFood(objPos blockOff)
{
    int x, y;

    do {
        
    srand(time(NULL));   
    foodPos.x = (rand() % 18)+1;
    foodPos.y= (rand() %8)+1;
    } while (foodPos.isPosEqual(&blockOff));
    
}

    //rmber in objPos class you have an isPosEqual() method
    

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
    
}

