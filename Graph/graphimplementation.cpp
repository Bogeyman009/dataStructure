#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector <int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(int x: adj[i])
         cout<<x<<" ";
         cout<<"\n";
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

    print(adj,v);
    return 0;
}

/* Eg :- 
{
(0,1), 

(0,2), 

(1,2), 

(1,3) 

}
*/