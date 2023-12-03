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
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();


    myGM = new GameMechs(26, 13);
    myFood = new Food();
    object = new Player(myGM, myFood);
    
    objPosArrayList playerPosList; // Create an instance of objPosArrayList
    objPosArrayList* playerPosListPtr = &playerPosList; // Create a pointer to objPosArrayList
    myFood->generateFood(playerPosListPtr);
}

void GetInput(void)
{
    if (MacUILib_hasChar() != 0) {
        input = MacUILib_getChar();
        myGM->setInput(input); //using setter method to collect input 
        
        if (input == 'g' || input == 'G') { //debugging 
            // Clear away the current food
            // Generate a new random position for the food
            Player myPlayer(myGM, myFood);
            myFood->generateFood(myPlayer.getPlayerPos());
            
        }
     }
       
}

void RunLogic(void)
{
    char inputChar = myGM->getInput();
    object->updatePlayerDir();
    object->movePlayer();
 
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
    
    MacUILib_printf("The Score: %d\n", object->getPlayerScore(), myGM->getLoseFlagStatus());


}




void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

     MacUILib_Delay(50000);   

     MacUILib_printf("You scored: %d ", object->getPlayerScore());

    MacUILib_Delay(50000);  

  
    MacUILib_uninit();

    


    delete myGM;
    delete object;
}
