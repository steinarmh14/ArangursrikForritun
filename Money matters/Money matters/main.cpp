//
//  main.cpp
//  Money matters
//
//  Created by Steinar Marinó Hilmarsson on 5/13/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdlib.h>

using namespace std;

struct union_find {
    
    int N;
    vector<int> parent;
    vector<int> sizeVec;
    
    
    union_find(int n) {
        N = n;
        sizeVec = vector<int>(n,1);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    
    void unite(int x, int y) {
        if(find(x) == find(y))
        {
            return;
        }
        else
        {
            sizeVec[find(y)] += sizeVec[find(x)];
            parent[find(x)] = find(y);
        }
        
    }
    void clear()
    {
        sizeVec = vector<int>(N,1);
        parent = vector<int>(N);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
        
    }
};

int main(int argc, const char * argv[]) {
    
    int numberOfFriends;
    cin >> numberOfFriends;
    
    int friendships;
    cin >> friendships;
    
    union_find uf(numberOfFriends);
    vector<int> vec;
    vector<int> s;
    
    for(int i = 0; i < numberOfFriends;i++)
    {
        int numb;
        cin >> numb;
        vec.push_back(numb);
    }
    
    
    for(int i  = 0; i < numberOfFriends; i++)
    {
        s.push_back(0);
    }
    
    for(int i = 0; i < friendships; i++)
    {
        int person1, person2;
        cin >> person1 >> person2;

        uf.unite(person1, person2);
    }
    
    for(int i = 0; i < numberOfFriends; i++)
    {
        s[uf.find(i)] += vec[i];
    }
    
    bool tof = true;
    
    for(int i = 0; i < s.size();i++)
    {
        if(s[i] != 0)
        {
            tof = false;
            break;
        }
    }
    
    if(tof)
    {
        cout << "POSSIBLE";
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
  
    
    return 0;
}
