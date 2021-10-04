#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void BFS_graph(vector <int> adj[],int v,bool visited[])
{
    queue<int> q;
    visited[v]=true;
    q.push(v);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
void BFS_dis(vector<int> adj[],int v)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i]=false;

    for(int i=0;i<v;i++)
      if(visited[i]==false)
            BFS_graph(adj,i,visited);
    
}

int main()
{
    int V = 5;
    vector<int> adj[V];
  
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    BFS_dis(adj, V);
    return 0;
} 