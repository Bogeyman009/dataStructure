#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];


void addEdge(int u,int v)
{
    adj[u].push_back(v);
}

void DFS_rev(int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(int u:adj[s])
        if(visited[u]==false)
            DFS_rev(u,visited);
}

void DFS(int v,int s)
{
    bool visited[v];

    for(int i=0;i<v;i++)
     visited[i]=false;

     for(int i=0;i<v;i++)
        if(visited[i]==false)
            DFS_rev(i,visited);
}

int main()  
{
    int v,a,b;
    cin>>v;
    vector <int> adj[v];
    for(int i=0;i<v;i++)
        {
            cin>>a>>b;
            addEdge(a,b);
        }
     DFS(v,0);

    return 0;
}