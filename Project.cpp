#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"



using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
char coordinates[9][19]; 
char input; 

GameMechs* myGM;
Player* object;
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

    myPos.setObjPos(2,3,'*');

    myGM = new GameMechs(26, 13); //make board size 26x13
    object = new Player(myGM);

    //exitFlag = false;
}

void GetInput(void)
{

    if(MacUILib_hasChar() !=0){
        char input = MacUILib_getChar();

        myGM->setInput(input); //using setter method to collect input 
        // speedInput = MacUILib_getChar();
    
    } 
   
}

void RunLogic(void)
{
    char inputChar = myGM->getInput();
       
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    char matrix[myGM->getBoardSizeY()][myGM->getBoardSizeX()];
    
    objPos tempPos;
    object->getPlayerPos(tempPos); //get player postion 

    int x,y;

    for (y=0; y<myGM->getBoardSizeY(); y++) {
        for (x=0; x<myGM->getBoardSizeX();x++) {
            if (y == 0 || x == 0 || x== myGM->getBoardSizeX()-1 || y== myGM->getBoardSizeY()-1) {
                matrix[y][x]='#';
            }

            else if (x == tempPos.x || y == tempPos.y) {
                matrix[y][x]= tempPos.symbol;
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
}



/*
    int row, col;

        for(row=0; row <= 8; row++){
        for(col=0; col <= 18; col++){
            if(row == 0 || row == 8 || col == 0 || col == 18){
                coordinates[row][col] = '#';

            } else{
                coordinates[row][col] = ' ';
            }


        }
    } 



    int x, y;

    // arbitrary symbols
    
    coordinates[4][6] = 'L';
    coordinates[3][7] = 'f';
    coordinates[2][1] = 'a';
    coordinates[5][4] = 'Q';
    coordinates[myPos.x][myPos.y] = myPos.symbol;

    for(x=0; x <= 8; x++){
        
        for(y=0; y <= 18; y++){
            MacUILib_printf("%c", coordinates[x][y]);
        }

        MacUILib_printf("\n");
    }
    }
    */



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
