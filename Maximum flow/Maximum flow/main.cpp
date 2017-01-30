#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct edge {
    int u, v, cap;
    edge *rev;
    bool forward;
    edge(int _u, int _v, int _cap, bool forw)
    : u(_u), v(_v), cap(_cap), forward(forw) { }
};

struct flow_network {
    
    int n;
    vector<vector<edge*> > adj;
    flow_network(int _n) : n(_n), adj(_n) { }
    
    void add_edge(int u, int v, int cap) {
        edge *e = new edge(u, v, cap, true);
        edge *rev = new edge(v, u, 0, false);
        e->rev = rev;
        rev->rev = e;
        adj[u].push_back(e);
        adj[v].push_back(rev);
    }
    
    int augment(int s, int t) {
        vector<edge*> back(n, (edge*)0);
        queue<int> Q;
        Q.push(s);
        back[s] = (edge*)1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i]->v;
                if (back[v] == NULL && adj[u][i]->cap > 0) {
                    back[v] = adj[u][i];
                    Q.push(v);
                }
            }
        }
        
        if (back[t] == NULL)
            return 0;
        
        stack<edge*> S;
        S.push(back[t]);
        int bneck = back[t]->cap;
        while (S.top()->u != s) {
            S.push(back[S.top()->u]);
            bneck = min(bneck, S.top()->cap);
        }
        
        while (!S.empty()) {
            S.top()->cap -= bneck;
            S.top()->rev->cap += bneck;
            S.pop();
        }
        
        return bneck;
    }
    
    int max_flow(int source, int sink) {
        int flow = 0;
        while (true) {
            int f = augment(source, sink);
            if (f == 0) {
                break;
            }
            
            flow += f;
        }
        
        return flow;
    }
};

int main() {
    
    int numberOfNodes, numberOfEdges,sourceDest,sinkDest;
    cin >> numberOfNodes >> numberOfEdges >> sourceDest >> sinkDest;
    
    flow_network g(numberOfNodes);
    
    for(int i = 0; i < numberOfEdges; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g.add_edge(u,v,c);
    }
    
    vector<vector <int> > v;
    int numb = g.max_flow(sourceDest,sinkDest);
    
    for(int i = 0; i < numberOfNodes; i++)
    {
        for(int j = 0; j < g.adj[i].size(); j++)
        {
            if(g.adj[i][j]->forward == true && g.adj[i][j]->rev->cap > 0)
            {
                vector<int> temp;
                temp.push_back(g.adj[i][j]->u);
                temp.push_back(g.adj[i][j]->v);
                temp.push_back(g.adj[i][j]->rev->cap);
                v.push_back(temp);
            }
        }
    }
    
    cout << numberOfNodes << " " << numb << " " << v.size() << endl;
    
    sort(v.begin(),v.end());
    
    for(int i = 0; i < v.size();i++)
    {
        cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
    }
    
    
    return 0;
}
