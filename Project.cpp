#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
char coordinates[9][19]; 
char input; 

GameMechs* myGM;
Player* object;
Food* myFood; 
objPos myPos;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        // object->updatePlayerDir();
        // object->movePlayer();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    // objpos.setObjPos(2,3,'*');

    myGM = new GameMechs(26, 13);
    myFood = new Food();
    object = new Player(myGM, myFood);
    
    objPos tempPos;
    myFood->generateFood(tempPos); 



    

    //exitFlag = false;
}

void GetInput(void)
{
    if (MacUILib_hasChar() != 0) {
        input = MacUILib_getChar();
        myGM->setInput(input); //using setter method to collect input 
        
        if (input == 'g' || input == 'G') { //debugging 
            // Clear away the current food
            // Generate a new random position for the food
            myFood->generateFood(myPos);
        }
     }
        // speedInput = MacUILib_getChar();
}

void RunLogic(void)
{
    char inputChar = myGM->getInput();
    object->updatePlayerDir();
    object->movePlayer();

     if (inputChar == 's' || inputChar == 'S') {
        myGM->incrementScore();
        MacUILib_printf("Score incremented! New score: %d\n", myGM->getScore());
    }
       
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    objPosArrayList* playerBody = object->getPlayerPos(); // entire player pos list
   

    char matrix[myGM->getBoardSizeY()][myGM->getBoardSizeX()];
    
    objPos tempPos;
    object->getPlayerPos(); //get player postion 

     objPos tempBody;

    objPos foodPos;
    myFood->getFoodPos(foodPos);
    bool drawn;

    int x,y;

    for (y=0; y<myGM->getBoardSizeY(); y++) {
        
        for (x=0; x<myGM->getBoardSizeX();x++) {
             drawn = false;


            for(int k = 0; k < playerBody->getSize(); k++){
                playerBody->getElement(tempBody, k);

                if(tempBody.x == x && tempBody.y == y){
                    
                    matrix[y][x] = tempBody.symbol;
                    drawn = true;
                    break;
                }
                
            }

            if(drawn) continue; // if player was drawn don't draw everything below

            if (y == 0 || x == 0 || x== myGM->getBoardSizeX()-1 || y== myGM->getBoardSizeY()-1) {
                matrix[y][x]='#';
            }
            
            else if (x == foodPos.x && y == foodPos.y) {
                matrix[y][x] = foodPos.symbol;

            }

            else {
                matrix[y][x] = ' ';
            }
    }
    }

    for (int y =0; y<myGM->getBoardSizeY(); y++){

        for (int x =0; x <myGM->getBoardSizeX(); x++){
            MacUILib_printf("%c", matrix[y][x]);
        }
        MacUILib_printf("\n");

    }
    
        
    
    MacUILib_printf("The score is %d and loseFlag is set to %d\n", myGM->getScore(), myGM->getLoseFlagStatus());

    for(int f = 0; f < playerBody->getSize(); f++){
        playerBody->getElement(tempBody,f);

        MacUILib_printf("<%d, %d> ", tempBody.x, tempBody.y);

    }
}



void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete myGM;
    delete object;
}
