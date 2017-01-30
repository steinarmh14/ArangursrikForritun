#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;



struct flow_network {
    
    struct edge {
        int u, v, cap;
        edge *rev;
        bool forward;
        edge(int _u, int _v, int _cap, bool forw)
        : u(_u), v(_v), cap(_cap), forward(forw) { }
    };
    
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
    vector<bool> visited(numberOfNodes, false);

    for(int i = 0; i < numberOfEdges; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g.add_edge(u,v,c);
    }
    
    stack<int> s;
    g.max_flow(sourceDest, sinkDest);
    s.push(sourceDest);
    visited[sourceDest] = true;
    
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        visited[top] = true;
        
        for(int j = 0; j < g.adj[top].size(); j++)
        {
            if(g.adj[top][j]->cap > 0 && (!visited[g.adj[top][j]->v]))
            {
                s.push(g.adj[top][j]->v);
                visited[g.adj[top][j]->v] = true;
            }
        }
    }
    
    int counter = 0;
    
    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i])
        {
            counter++;
        }
    }
    
    cout << counter << endl;
    
    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i])
        {
            cout << i << endl;
        }
    }
    
    return 0;
}
