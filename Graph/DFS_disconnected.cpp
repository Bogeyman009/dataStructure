#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFS_rev(vector<int> adj[],int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(int x:adj[s])
            if(visited[x]==false)
                DFS_rev(adj,x,visited);
}

void DFS(vector<int> adj[],int v)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    
    for(int i=0;i<v;i++)
        if(visited[i]==false)
            DFS_rev(adj,i,visited);
}
int main()
{
    int v,a,b;                        
    cin>>v;
    vector <int> adj[v];
    for(int i=0;i<v;i++)
        {
            cin>>a>>b;
            addEdge(adj,a,b);
        }
    DFS(adj,v);

    return 0;
}

