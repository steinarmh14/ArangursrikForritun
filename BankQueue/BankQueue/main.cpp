//
//  main.cpp
//  BankQueue
//
//  Created by Steinar Marinó Hilmarsson on 5/8/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//  unnið með Sigmari Bjarna og Agli gaut

#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main(int argc, const char * argv[]) {
    
    vector<vector<int> > v(50);
    multiset<int> s;
    
    int n = 0;
    cin >> n;
    int t = 0;
    cin >> t;

    int counter = 0;
    while(counter < n)
    {
        int ci = 0;
        cin >> ci;
        int ti = 0;
        cin >> ti;
        v[ti].push_back(ci);
        counter++;
    }

    int sum = 0;

    for (int i = v.size(); i-- > 0;)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            s.insert(v[i][j]);
        }
        
        if(!s.empty())
        {
            sum += *s.rbegin();
            s.erase(s.find(*s.rbegin()));
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
