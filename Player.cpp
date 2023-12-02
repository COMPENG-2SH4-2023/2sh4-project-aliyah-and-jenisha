#include "Player.h"

objPosArrayList* playerPosList;


Player::Player(GameMechs* thisGMRef, Food* thisFoodRef) : mainGameMechsRef(thisGMRef), foodRef(thisFoodRef)
{
    //mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
     tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() /2, mainGameMechsRef->getBoardSizeY() /2, '*'); // easier way to do this

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete(mainGameMechsRef);

    delete playerPosList;
}

 objPosArrayList* Player::getPlayerPos()
{
     return playerPosList;

    



}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 

    GameMechs* thisGMRef;

    char input, previousDirection;

    input = thisGMRef->getInput();


    if(input != 0)  // if not null character
    { 
        switch(input){
            case 'w':
                if (myDir != DOWN) {
                    myDir = UP;
                }
                break;
            
            case 'a':
                if (myDir != RIGHT) {
                    myDir = LEFT;
                }
                break;

             case 's':
                if (myDir != UP) {
                    myDir = DOWN;
                }
                break;
            
            case 'd':
                if (myDir != LEFT) {
                    myDir = RIGHT;
                }
                break;
            
            default:
                break;
        }
        }
    }




void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos currHead; 
    playerPosList->getHeadElement(currHead);


    switch(myDir){
        case UP:
            currHead.y--;
            break;
        case DOWN:
            currHead.y++;
            break;
        case RIGHT:
            currHead.x++;
            break;
        case LEFT:
            currHead.x--;
            break;
    }
    if(currHead.x > 24){
        currHead.x = 2; 

    } else if(currHead.x < 2){
        currHead.x = 24;

    } else if(currHead.y < 2){
        currHead.y = 10;
    } else if(currHead.y > 11){
        currHead.y = 2;
    }

   playerPosList->insertHead(currHead);

    // Check if the head overlaps with the food
    if (checkFoodConsumption())
    {
        // If yes, increase the player length without removing the tail
        increasePlayerLength();

        // Generate new food
        foodRef->generateFood(currHead);
    }
    else
    {
        // If no, regular insert + remove to complete the snake movement
        playerPosList->removeTail();
    }
}


bool Player::checkFoodConsumption()
{
    objPos currHead;
    playerPosList->getHeadElement(currHead);

    objPos foodPos;
    foodRef->getFoodPos(foodPos);

    return (currHead.x == foodPos.x && currHead.y == foodPos.y);
}

void Player::increasePlayerLength()
{
    // Insert the head, but DO NOT remove the tail
    // This will cause the list size, hence the snake length, to grow by 1
    // The function already does this during food consumption, so this is just an example
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    playerPosList->insertHead(currHead);
}

bool Player::checkSelfCollision(){

    objPos currHead; 
    playerPosList->getHeadElement(currHead);

     for(int k = 0; k < playerBody->getSize(); k++){
        playerBody->getElement(tempBody, k);

        if(tempBody.x == currHead.x && tempBody.y == currHead.y){
            return true;
        }
     }

     return false;


}

