//
//  main.cpp
//  minimum scalar product
//
//  Created by Steinar Marinó Hilmarsson on 5/8/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//  unnið með Sigmari Bjarna og Agli Gaut

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<long long> v1;
    vector<long long> v2;
    
    int tc = 0;
    cin >> tc;
    
    int counter = 0;
    while(counter < tc)
    {
        
        int howManyNumbers = 0;
        cin >> howManyNumbers;
        
        int counter2 = 0;
        while(counter2 < howManyNumbers)
        {
            int n = 0;
            cin >> n;
            v1.push_back(n);
            counter2++;
        }

        counter2 = 0;
        while(counter2 < howManyNumbers)
        {
            int n = 0;
            cin >> n;
            v2.push_back(n);
            counter2++;
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        long long msp= 0;
        
        for(unsigned int i = 0; i < v1.size(); i++)
        {
            long long highest = v2[v2.size() - 1 - i];
            long long smallest = v1[i];
            msp += (smallest * highest);
        }
        
        cout << "Case #" << counter+1 << ": " << msp << endl;
        
        v1.clear();
        v2.clear();
        counter++;
    }
    
    
    return 0;
}