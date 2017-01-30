//
//  main.cpp
//  Burrowswheeler
//
//  Created by Steinar Marinó Hilmarsson on 5/15/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct suffix_array {
    struct entry {
        pair<int, int> nr;
        int p;
        
        bool operator <(const entry &other) const {
            return nr < other.nr;
        }
    };
    
    string s;
    int n;
    vector<vector<int> > P;
    vector<entry> L;
    vector<int> idx;
    
    suffix_array(string _s) : s(_s), n(s.size()) {
        L = vector<entry>(n);
        P.push_back(vector<int>(n));
        idx = vector<int>(n);
        
        for (int i = 0; i < n; i++) {
            P[0][i] = s[i];
        }
        
        for (int stp = 1, cnt = 1; (cnt >> 1) < n; stp++, cnt <<= 1) {
            P.push_back(vector<int>(n));
            for (int i = 0; i < n; i++) {
                L[i].p = i;
                L[i].nr = make_pair(P[stp - 1][i],
                                    i + cnt < n ? P[stp - 1][i + cnt] : -1);
            }
            
            sort(L.begin(), L.end());
            for (int i = 0; i < n; i++) {
                if (i > 0 && L[i].nr == L[i - 1].nr) {
                    P[stp][L[i].p] = P[stp][L[i - 1].p];
                } else {
                    P[stp][L[i].p] = i;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            idx[P[P.size() - 1][i]] = i;
        }
    }
    
    int lcp(int x, int y) {
        int res = 0;
        if (x == y) return n - x;
        for (int k = P.size() - 1; k >= 0 && x < n && y < n; k--) {
            if (P[k][x] == P[k][y]) {
                x += 1 << k;
                y += 1 << k;
                res += 1 << k;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[])
{
    
    string str = "";
    
    while (getline(cin,str))
    {
        str += str;
        suffix_array suffArr(str);
        int counting = 0;
        
        while(counting < str.size())
        {
            int index = (suffArr.idx[counting]+(str.size()/2)-1);
            
            if(suffArr.idx[counting] < str.size()/2)
            {
                cout << str[index];
                
            }
            
            counting++;
        }

        cout << endl;
        str = "";
    }
    
    return 0;
}
