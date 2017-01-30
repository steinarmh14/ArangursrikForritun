//
//  main.cpp
//  jabuke
//
//  Created by Steinar Marinó Hilmarsson on 5/15/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//  unnið með sigmari bjarna og agli gaut

#include <iostream>
#include <complex>
#include <iomanip>
using namespace std;

typedef complex<double> point;

int main()
{
    point a, b, c, vec1, vec2;
    
    double x = 0.0, y = 0.0;
    cin >> x >> y;
    a = point(x, y);
    
    cin >> x >> y;
    b = point(x, y);
    
    cin >> x >> y;
    c = point(x, y);
    
    vec1 = b - a;
    vec2 = c - a;
    
    double areaOfLand = 0.0;
    areaOfLand = abs(((real(vec1) * imag(vec2)) - (imag(vec1) * real(vec2)))) / 2;
    
    
    int howManyTrees;
    cin >> howManyTrees;
    
    int appleCounter = 0;
    int counter = 0;
    while(counter < howManyTrees)
    {
        point t;
        cin >> x >> y;
        t = point(x, y);
        
        vec1 = b - t;
        vec2 = c - t;
        
        double onLawn = 0.0;
        onLawn = abs(((real(vec1) * imag(vec2)) - (imag(vec1) * real(vec2)))) / 2;
        vec1 = c - t;
        vec2 = a - t;
        onLawn += (abs(((real(vec1) * imag(vec2)) - (imag(vec1) * real(vec2)))) / 2);
        vec1 = b - t;
        vec2 = a - t;
        onLawn += (abs(((real(vec1) * imag(vec2)) - (imag(vec1) * real(vec2)))) / 2);
        
        if(onLawn == areaOfLand)
        {
            appleCounter++;
        }
        
        counter++;
    }
    
    cout << fixed << setprecision(1) << areaOfLand << endl;
    cout << appleCounter << endl;
    
    return 0;
}