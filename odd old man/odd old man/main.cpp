//
//  main.cpp
//  odd old man
//
//  Created by Steinar Marinó Hilmarsson on 5/13/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    int tc = 0;
    cin >> tc;
    
    int counter = 0;
    while(counter < tc)
    {
        int howManyGuests = 0;
        cin >> howManyGuests;
        
        vector<int> g;
        
        for(int i = 0; i < howManyGuests; i++)
        {
            int guest;
            cin >> guest;
            bool found = false;
            for(int j = 0; j < g.size();j++)
            {
                if(g[j] == guest)
                {
                    g.erase(g.begin()+j);
                    found = true;
                }
            }
            
            if(!found)
            {
                g.push_back(guest);
            }
            
        }
        
        cout << "Case #" << counter+1 << ": " << g[0] << endl;
        
        g.clear();
        counter++;
    }
    
    
    
    
    
    return 0;
}
