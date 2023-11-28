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

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);


};

#endif