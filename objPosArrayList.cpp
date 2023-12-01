#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here


objPosArrayList::objPosArrayList(){
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP; 
    aList = new objPos[ARRAY_MAX_CAP];
}


objPosArrayList::~objPosArrayList(){
     delete[] aList; 

}

void objPosArrayList::insertHead(objPos thisPos){
    for (int i = sizeList; i>0; i--)//size list is pointing to where the next element will be inserted
     {
        aList[i] = aList[i-1];
     }


    aList[0] = thisPos;
    sizeList++;
}


void objPosArrayList::insertTail(objPos thisPos){
    if (sizeList == sizeArray)
    {
        //cout << "ArrayList is full." << endl;
        return;
    }


    //must shift elements to make space 

    aList[sizeList] = thisPos;
    sizeList++; 
}

void objPosArrayList::removeHead(){
    if(sizeList == 0){
        // error message
        return;
    } else{
        for (int i = 0; i<sizeList-1; i--)//size list is pointing to where the next element will be inserted
        {
            aList[i] = aList[i+1];

        
        }

        sizeList--;
    }

    
}

void objPosArrayList::removeTail(){

    if(sizeList == 0){
         // error message
         return;
    } else{

        sizeList--;
    }


    

}

void objPosArrayList::getHeadElement(objPos &returnPos){

    returnPos = aList[0];

}

void objPosArrayList::getTailElement(objPos &returnPos){
    returnPos = aList[sizeList-1];



}

void objPosArrayList::getElement(objPos &returnPos, int index){
    returnPos = aList[index];
}

int objPosArrayList::getSize(){
    return sizeList;
}




