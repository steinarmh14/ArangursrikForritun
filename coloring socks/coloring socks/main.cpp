//
//  main.cpp
//  coloring socks
//
//  Created by Steinar Marinó Hilmarsson on 5/13/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {

    
    int s, c, k;
    cin >> s >> c >> k;
    
    vector<int> vec;
    
    if(c == 1)
    {
        for(int i = 0; i < s; i++)
        {
            int numb;
            cin >> numb;
            vec.push_back(numb);
        }
        
        cout << vec.size();
        
    }
    else
    {
        int washingMachines = 0;
        
        for(int i = 0; i < s; i++)
        {
            int numb;
            cin >> numb;
            vec.push_back(numb);
        }
        
        sort(vec.begin(),vec.end());
        
        vector<int> v;
        
        for(int i = 0; i < vec.size();i++)
        {
            
            if(v.size() == c)
            {
                washingMachines++;
                v.clear();
            }
            
            if(v.size() < 1)
            {
                v.push_back(vec[i]);
            }
            else if(v.size() >= 1 && abs(v[0] - vec[i]) > k)
            {
                washingMachines++;
                v.clear();
                v.push_back(vec[i]);
                
            }
            else if(v.size() >= 1 && abs(v[0] - vec[i]) <= k)
            {
                v.push_back(vec[i]);
            }
            
        }
        
        if(v.size() > 0)
        {
            washingMachines++;
            cout << washingMachines;
        }
        else
        {
            cout << washingMachines;
        }
        
    }
    
    return 0;
}
