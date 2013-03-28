//
//  main.cpp
//  project_interpretter
//
//  Created by Jon Gautsch on 3/26/13.
//  Copyright (c) 2013 Jon Gautsch. All rights reserved.
//

#include <iostream>
#include "Interpreter.h"

int main(int argc, const char * argv[])
{
    /*
    
    Here is the numeric codes for the different commands of the "language" to be used in our game
        
        1 - run
        2 - jump
        3 - turn
        4 - kick
        5 - open loop
        6 - close loop
        
        */

    

    
    vector<int> program = {1, 2, 3, 4, 5, 2, 6};
    vector<int> params = {4, 1, 0, 2, 4, 4, 0};
    
    Interpreter lang(program, params);
    
    
    return 0;
}

