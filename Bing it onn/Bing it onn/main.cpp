//
//  main.cpp
//  Bing it onn
//
//  Created by Steinar Marinó Hilmarsson on 5/15/16.
//  Copyright © 2016 Steinar Marinó Hilmarsson. All rights reserved.
//  unnið með sigmari bjarna og agli gaut

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct node
{
    node* children[26];
    bool is_end;
    int counter = 0;
    node()
    {
        memset(children, 0, sizeof(children));
        is_end = false;
    }
};
void insert(node* nd, char *s)
{
    if (*s)
    {
        if (!nd->children[*s - 'a'])
            nd->children[*s - 'a'] = new node();
        
        nd->counter++;
        insert(nd->children[*s - 'a'], s + 1);
    }
    else
    {
        nd->counter++;
        nd->is_end = true;
    }
}
int contains(node* nd, char *s)
{
    if (*s)
    {
        if (!nd->children[*s - 'a'])
            return false;
        return contains(nd->children[*s - 'a'], s + 1);
    }
    else
    {
        return nd->counter;
    }
}


int main(int argc, const char * argv[]) {
    
    node *trie = new node();
    int tc;
    char ch[40];
    cin >> tc;
    int counting = 0;
    
    while(counting < tc)
    {
        cin >> ch;
        cout << contains(trie, ch) << endl;
        insert(trie, ch);
        counting++;
    }
    
    return 0;
}
