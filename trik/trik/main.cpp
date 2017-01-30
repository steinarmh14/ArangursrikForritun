//
//  main.cpp
//  trik
//
//  Created by Steinar Marinó Hilmarsson on 5/13/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    
    string str;
    cin >> str;
    
    
    int ball = 1;
    
    for(int i = 0;i < str.length(); i++)
    {
        char ch = str[i];
        
        if(ch == 'A' && ball == 1)
        {
            ball = 2;
        }
        else if(ch == 'A' && ball == 2)
        {
            ball = 1;
        }
        
        if(ch == 'B' && ball == 2)
        {
            ball = 3;
        }
        else if(ch == 'B' && ball == 3)
        {
            ball = 2;
        }
        
        if(ch == 'C' && ball == 3)
        {
            ball = 1;
        }
        else if(ch == 'C' && ball == 1)
        {
            ball = 3;
        }
    }
    
    cout << ball;
    
    return 0;
}
