//
//  main.cpp
//  Narrow Art Galler
//
//  Created by Steinar Marinó Hilmarsson on 5/8/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//  unnið með Sigmari Bjarna og Agli Gaut

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int inf = 1000000000;
int mem[210][209][2][2];

int dp(int numRows, int numRooms, bool tof1, bool tof2, int arr[200][2])
{
    if(numRooms == 0)
    {
        return 0;
    }
    else if(numRows < 0)
    {
        return inf;
    }
    else
    {
        if(mem[numRows][numRooms][tof1][tof2] != -1)
        {
            return mem[numRows][numRooms][tof1][tof2];
        }
        
        int result = 0;
        
        if(tof1 == false && tof2 == false)
        {
            result = min(min(arr[numRows][0] + dp(numRows-1, numRooms-1, true, false, arr), dp(numRows-1, numRooms, false, false, arr)), arr[numRows][1] + dp(numRows-1, numRooms-1, false, true, arr));
        }
        if(tof1 == true && tof2 == false)
        {

            result = min(arr[numRows][0] + dp(numRows-1, numRooms-1, true, false, arr), dp(numRows-1, numRooms, false, false, arr));
        }
        if(tof1 == false && tof2 == true)
        {
            result = min(arr[numRows][1] + dp(numRows-1, numRooms-1, false, true, arr), dp(numRows-1, numRooms, false, false, arr));
        }
        
        
        mem[numRows][numRooms][tof1][tof2] = result;
        return result;
    }
    
    return 0;
}

int main(int argc, const char * argv[])
{
    memset(mem, -1, sizeof(mem));
    int numRows = 0;
    int numRooms = 0;
    int arr[200][2];
    bool tof1 = false;
    bool tof2 = false;

    
    while (cin >> numRows >> numRooms)
    {
        if(numRows == 0 && numRooms == 0)
        {
            break;
        }
        
        int sum = 0;
        int counter = 0;
        
        while(counter < numRows)
        {
            int a;
            cin >> a;
            int b;
            cin >> b;
            arr[counter][0] = a;
            arr[counter][1] = b;
            int numb = a+b;
            sum += numb;
            counter++;
        }
       
        int retVal = dp(numRows-1, numRooms, tof1, tof2, arr);
        retVal = sum - retVal;
        cout << retVal << endl;
    }
    
    return 0;
}