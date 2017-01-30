//
//  main.cpp
//  Polygon
//
//  Created by Steinar Marinó Hilmarsson on 5/15/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//  unnið með Sigmari Bjarna og Agli Gaut

#include <iostream>
#include <complex>
#include <vector>
#include <iomanip>
using namespace std;

#define P(x) const point x
const double EPS = 1e-9;

typedef complex<double> point;

double cross(P(a), P(b))
{
    return real(a)*imag(b) - imag(a)*real(b);
}

int main(int argc, const char * argv[]) {
    
    vector<point> pointVec;
    
    do {
        int n;
        cin >> n;
        double sum = 0.0;
        if(n == 0)
        {
            break;
        }
        
        point p;
        double x = 0;
        double y = 0;
        
        int fillVec = 0;
        while(fillVec < n)
        {
            cin >> x >> y;
            point p(x,y);
            pointVec.push_back(p);
            fillVec++;
        }

        
        for (int i = 1; i < pointVec.size()-1; i++)
        {
            point u = pointVec[i] - pointVec[0];
            point v = pointVec[i+1] - pointVec[0];
            sum += cross(u, v);
        }
        
        sum = sum/2;
        
        if (sum > 0)
        {
            cout << "CCW " << fixed << setprecision(1) << sum << endl;
            
        }
        else
        {
            cout << "CW " << fixed << setprecision(1) << -sum << endl;
        }
        
        sum = 0.0;
        pointVec.clear();
    }while (true);
    
    
    return 0;
}