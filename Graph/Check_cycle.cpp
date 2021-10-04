#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int v,int u)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}
bool CheckCycle(vector<int> adj[],int s,bool visited[],int par)
{
    visited[s]=true;
    for(int u:adj[s])
    {
    if(visited[u]==false)
        if(CheckCycle(adj,u,visited,s)==true)
         return true;
         else
         if(u != par)
         return true;
    }
    return false;
}

bool dfsCyclic(vector<int> adj[],int v)
{
   bool visited[v];
   for(int i=0;i<v;i++)
        visited[i]=false;

    for(int i=0;i<v;i++)
       if(visited[i]==false)
            if(CheckCycle(adj,i,visited,-1)==true)
                return true;
            
            return false;
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
    if(dfsCyclic(adj,v))
    cout<<"Given graph has cycle";
    else
    cout<<"Given graph donot have cycle";

    return 0;
}