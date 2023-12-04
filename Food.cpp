#include "GameMechs.h"
#include "Food.h"
#include "MacUILib.h"


#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <cstdlib> //provides srand() and rand()
//#include <time.h> //provides time

using namespace std;



Food::Food() //constructor
{
   foodPos.setObjPos(-1, -1, 'o'); //intalize foodpos outside of the game board

}



Food::~Food(){} //deconstructor



void Food::generateFood(objPosArrayList* playerPosList)
{
   int x, y;


   do {
    srand(time(NULL));  
    foodPos.x = (rand() % 18)+1;
    foodPos.y= (rand() %8)+1;
    } while (checkFoodOnSnake(*playerPosList));
  
}


bool Food::checkFoodOnSnake(objPosArrayList &playerPosList) { //extra method added to check if any food is detected on snake body
    objPos tempPos;

    for (int i = 0; i < playerPosList.getSize(); ++i) {
        playerPosList.getElement(tempPos, i);

        if (tempPos.x == foodPos.x && tempPos.y == foodPos.y) { 
            return true;  // Food is on snake body
        }
    }

    return false;  // Food is not on the snake body
}


void Food::getFoodPos(objPos &returnPos)
{
   returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}







