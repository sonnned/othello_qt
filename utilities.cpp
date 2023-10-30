#include"utilities.h"
#include <iostream>
#include "macros.h"



bool validator(int value)
{
    bool flag;
    if(value<0 || value>BOARD_HEIGHT-1){
        flag=false;
        return flag;
    }
    else{
        flag=true;
        return flag;
    }
}


