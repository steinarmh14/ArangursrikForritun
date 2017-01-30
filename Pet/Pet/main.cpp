//
//  main.cpp
//  Pet
//
//  Created by Steinar Marinó Hilmarsson on 5/25/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    int a,b,c,d;
    
    int contestant;
    int sum = 0;
    
    bool first = true;
    
    for(int i = 0; i < 5;i++)
    {
        cin >> a >> b >> c >> d;
        
        if(first)
        {
            contestant = i+1;
            sum = a + b + c +d;
            first = false;
        }
        else
        {
            int contestSum = a + b + c + d;
            if(contestSum > sum)
            {
                contestant = i+1;
                sum = contestSum;
            }
        }
    }
    
    
    cout << contestant << " " << sum;
    
    
    
    
    return 0;
}
