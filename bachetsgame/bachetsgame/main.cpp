//
//  main.cpp
//  bachetsgame
//
//  Created by Steinar Marinó Hilmarsson on 5/15/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//  unnið með sigmari bjarna og agli gaut

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int howManyStones;
    int m;
    vector<int> stoneVec;
    
    while(cin >> howManyStones >> m)
    {
        vector<int> vec(howManyStones+1, 0);
        
        int counter = 0;
        while(counter < m)
        {
            int n;
            cin >> n;
            stoneVec.push_back(n);
            counter++;
        }

        for(int i = 1; i < howManyStones + 1; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i < stoneVec[j])
                {
                    continue;
                }
                
                if(vec[i - stoneVec[j]] != 1)
                {
                    vec[i] = 1;
                    break;
                }
            }
        }
        
        if(vec[howManyStones] == 1)
        {
            cout << "Stan wins" << endl;
        }
        else
        {
            cout << "Ollie wins" << endl;
        }
        
        stoneVec.clear();
        vec.clear();
    }
    
    return 0;
}
