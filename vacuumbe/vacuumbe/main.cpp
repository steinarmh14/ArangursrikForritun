//
//  main.cpp
//  vacuumbe
//
//  Created by Steinar Marinó Hilmarsson on 5/15/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//  unnið með sigmari bjarna og agli gaut

#include <iostream>
#include <complex>
#include <math.h>
#include <iomanip>
using namespace std;

typedef complex<double> point;

int main()
{
    int tests;
    cin >> tests;

    int degree;
    float distance;
    float x = 0.0;
    float y = 0.0;
    float rad = 0.0;
    point beginning;
    int direction;


    int counter = 0;
    while(counter < tests)
    {
        int numOfSeg;
        cin >> numOfSeg;
        
        x = 0.0;
        y = 0.0;
        beginning = point(0, 0);
        direction = 90;
        
        int counting = 0;
        while(counting < numOfSeg)
        {
            cin >> degree >> distance;
        
            direction += degree;
            rad = direction * (M_PI / 180);
            beginning = polar(distance, rad);
            x += real(beginning);
            y += imag(beginning);
            
            counting++;
        }
        
        cout << fixed << setprecision(6) << x << " " << y << endl;
        
        counter++;
    }
    
    return 0;
}
