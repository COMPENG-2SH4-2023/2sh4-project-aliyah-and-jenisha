#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
char coordinates[9][19]; 


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

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
    

    for(x=0; x <= 8; x++){
        
        for(y=0; y <= 18; y++){
            MacUILib_printf("%c", coordinates[x][y]);
        }

        MacUILib_printf("\n");
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
}
