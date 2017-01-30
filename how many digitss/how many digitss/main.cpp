//
//  main.cpp
//  how many digitss
//
//  Created by Steinar Marinó Hilmarsson on 5/15/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//  unnið með sigmari bjarna og agli gaut

#include <iostream>
#include <cmath>
using namespace std;


int main(int argc, const char * argv[]) {
    
    double sum[1000001];
    sum[0] = 0;
    int counter = 1;
    
    while(counter < 1000001)
    {
        sum[counter] = log10(counter)+sum[counter-1];
        counter++;
    }

    int n;
    int retVal = 0;
    while (cin >> n)
    {
        retVal = floor(sum[n])+1;
        cout << retVal << endl;
    }
    return 0;
}
