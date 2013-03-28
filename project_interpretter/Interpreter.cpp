//
//  Interpreter.cpp
//  project_interpretter
//
//  Created by Jon Gautsch on 3/26/13.
//  Copyright (c) 2013 Jon Gautsch. All rights reserved.
//

#include "Interpreter.h"


Interpreter::Interpreter() {
    cout << "Interpreter initialized:\n\n";
    cout << "This is the wrong constructor though." << endl;
    
}


Interpreter::Interpreter(vector<int> program_codes, vector<int> params_codes) {
    
    // This will resize the v2int to the appropriate size
    // This prevents seg fault when accessing locations
    user_program.resize(program_codes.size());
    for (int i = 0; i < program_codes.size(); i++) {
        user_program[i].resize(2);
    }
    
    vector<int> temp = {0, 0};  // The little sets of two that will be pushed into the
                                // user program
    
    for (int i = 0; i < program_codes.size(); i++) {
//        temp[0] = program_codes[i];
//        temp[1] = params_codes[i];
//        user_program.push_back(temp);
        user_program[i][0] = program_codes[i];
        user_program[i][1] = params_codes[i];
    }
    
//    for (int i = 0; i < user_program.size(); i++) {
//        cout << "[ " << user_program[i][0] << ", " << user_program[i][1] << " ]" << endl;
//    }
    printRaw();
    parse( user_program );
}


void Interpreter::printRaw() {
    for (int i = 0; i < user_program.size(); i++) {
        cout << "[ " << user_program[i][0] << ", " << user_program[i][1] << " ]" << endl;
    }
}




/***********************************/
// parse() function:
//  -
/***********************************/

/*
 
 Wow, C++'s switch statement can only be used with ints.
 That's terrile.

 Here is the numeric codes for the different commands of the "language" to be used in our game
 
 1 - run
 2 - jump
 3 - turn
 4 - kick
 5 - open loop
 6 - close loop

 */

void Interpreter::parse( v2int program ) {
    
    
    for ( int i = 0; i < program.size(); i++ ) {
        
        switch (program[i][0]) {
            case 1:
                if (program[i][1] == 0) {
                    cout << "*Run one space" << endl;
                } else {
                    for (int j = 0; j < program[i][1]; j++) {
                        cout << "Run one space" << endl;
                    }
                }
                break;
                
            case 2:
                if (program[i][1] == 0) {
                    cout << "*Jump once" << endl;
                } else {
                    for (int j = 0; j < program[i][1]; j++) {
                        cout << "Jump once" << endl;
                    }
                }
                break;
                
            case 3:
                if (program[i][1] == 0) {
                    cout << "*Turn around" << endl;
                } else {
                    for (int j = 0; j < program[i][1]; j++) {
                        cout << "Turn around" << endl;
                    }
                }
                break;
                
            case 4:
                if (program[i][1] == 0) {
                    cout << "*Kick once" << endl;
                } else {
                    for (int j = 0; j < program[i][1]; j++) {
                        cout << "Kick once" << endl;
                    }
                }
                break;
                
            // It's about to get recursive
                
            case 5: {
                cout << "Open loop" << "  (should loop " << program[i][1] << " times)." << endl;

                // TODO: Refactor the following initialization lines to it's own function.
                v2int recursed_program;
                
                // Now find the lenght to the end of the loop
                int j = i;
                
                // NOTE: This initial implementation only allows for loops 1 level deep
                //       Could possibly add more layers by including another params list
                //       passed to the "interpreter" that would contain id's for each of
                //       the loops. That way, the closing tag of one loop wouldn't get
                //       confused with the closing tag of another, and loops could be
                //       inside of loops.
                while (program[j][0] != 6) {
                    j++;
                }
                
                recursed_program.resize(j);
                
                for (int k = 0; k < recursed_program.size(); k++) {
                    recursed_program[k].resize(2);
                }
                
                for (int k = i + 1; k < j-1; k++) {
                    recursed_program.push_back(program[k]);
                }
                
                // Now, however many times is specified in the params, loop
                for (int k = 0; k < program[i][1]; k++) {
                    parse(recursed_program);
                }
                //parse(recursed_program);
                
                break;
            }
                
            case 6:
                cout << "Close loop" << endl;
                break;
                
            default:
                break;
        }
    }
}