#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];

void addEdge(int v,int u)
{
    adj[u].push_back(v);
}

bool CheckCycle(int s,bool visited[],bool str[])
{
    visited[s]=true;
    str[s]=true;
    for(int u:adj[s])
    {
        if(visited[u]==false && CheckCycle(u,visited,str))
        return true;
        else if(str[u]==true)
        return true;
    }

    str[s]=false;
    return false;

}

bool dfsCyclic(int v)
{
   bool visited[v],str[v];
   for(int i=0;i<v;i++)
   {
       visited[i]=false;
       str[i]=false;
   }
   for(int i=0;i<v;i++)
        if(visited[i]==false)
            if(CheckCycle(i,visited,str)==true)
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
            addEdge(a,b);
        }
    if(dfsCyclic(v))
    cout<<"Given graph has cycle";
    else
    cout<<"Given graph donot have cycle";

    return 0;
}