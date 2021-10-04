#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFSgraph(vector <int> adj[],int v,int s)
{
    bool vis[v+1];
    for(int i=0;i<=v;i++)
        vis[i]=false;
    
    queue<int> q;
    vis[s]=true;
    q.push(s);
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        cout<<u <<" ";
    for(int v:adj[u])
        {
            if(vis[v]==false)
            {
                vis[v]=true;
                q.push(v);
            }
        }
    }
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
    BFSgraph(adj,v,0);

    return 0;
}

