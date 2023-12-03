#include "Player.h"
#include <iostream>


using namespace std; // so i can print for debugging



Player::Player(GameMechs* thisGMRef, Food* thisFoodRef) : mainGameMechsRef(thisGMRef), foodRef(thisFoodRef)
{

    myDir = STOP;

    objPos tempPos;
     tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() /2, mainGameMechsRef->getBoardSizeY() /2, '*'); // easier way to do this

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
 
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    //delete(mainGameMechsRef);

    delete playerPosList;
}

 objPosArrayList* Player::getPlayerPos()
{
     return playerPosList;


}

int Player::getPlayerScore() const {
    // Subtract 1 from the list size to map size 1 to score 0
    return playerPosList->getSize() - 1;
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
    Player* object; //get player postion

    object->getPlayerPos();


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


    if(currHead.x > mainGameMechsRef->getBoardSizeX()-2){
        currHead.x = 1; 

    } else if(currHead.x < 1){
        currHead.x = mainGameMechsRef->getBoardSizeX()-2;

    } else if(currHead.y < 1){
        currHead.y = mainGameMechsRef->getBoardSizeY()-2;
    } else if(currHead.y > mainGameMechsRef->getBoardSizeY()-2){
        currHead.y = 1;
    }



      if(checkSelfCollision(currHead)==true){

        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
        

    } else{
       

        if (checkFoodConsumption())
        {
             // If yes, increase the player length without removing the tail
            increasePlayerLength();
             // Generate new food
            foodRef->generateFood(playerPosList);
        }

        playerPosList->insertHead(currHead);
        playerPosList->removeTail();
 
        
    }

    // Check if the head overlaps with the food
   

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



bool Player::checkSelfCollision(objPos &head){
  
    objPos tempBodyPart;

    
     for(int k = 1; k < playerPosList->getSize(); k++){
        playerPosList->getElement(tempBodyPart, k);

        
        if(head.isPosEqual(&tempBodyPart)){
            return true;
        }
    }

     return false;


}

   
   





