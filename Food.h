#ifndef Food_H
#define Food_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"


class Food
{
   private:
       objPos foodPos;
  
   public:
       Food();
       ~Food();

       void generateFood(objPosArrayList* playerPosList);
       bool checkFoodOnSnake(objPosArrayList &playerPosList);
       void getFoodPos(objPos &returnPos);

};
#endif




