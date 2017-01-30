//
//  main.cpp
//  A Vicious Pikeman
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
    int howManyProblems = 0;
    cin >> howManyProblems;
    
    if(howManyProblems == 0) {
        cout << "0 0";
        return 0;
    }
    
    int contestTime = 0;
    cin >> contestTime;
    
    int a = 0;
    cin >> a;
    int b = 0;
    cin >> b;
    int c = 0;
    cin >> c;
    
    long long firstProblemTime = 0;
    cin >> firstProblemTime;
    vector<long long> v;
    v.push_back(firstProblemTime);
    long long timePerProblem = firstProblemTime;
    
    int counter = 1;
    
    while(counter < howManyProblems)
    {
        timePerProblem = (((a * timePerProblem + b) % c) + 1) % 1000000007;
        v.push_back(timePerProblem);

        counter++;
    }
    
    sort(v.begin(), v.end());
    
    long long timePenalty = 0;
    int problemsSolved = 0;

    long long number = 0;
    
    for(unsigned int i = 0; i < v.size(); i++)
    {
        number += v[i];
        if(number <= contestTime)
        {
            problemsSolved++;
            timePenalty += number;
        }
    }
    
    cout << problemsSolved << " " << timePenalty % 1000000007 << "\n";
    
    return 0;
}
