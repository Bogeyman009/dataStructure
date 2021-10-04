//to count the no of connected component and count the member in each component;


#define REP(i,n) for(int i=1;i<=n;i++)
#define mod 1000000007
#define vi vector<int>

#include<bits/stdc++.h>
using namespace std;

vi v[10001];
int vis[10001];
int dis, max_node;
void addEdge(int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
}

void dfs(int node,int d)
{
    vis[node]=1;
    if(d>dis)
    {
        dis=d;
        max_node=node;
    }
    for(int child:v[node])
        if(!vis[child])
            dfs(child,d+1);
}
int main()
{
    int t,n,m,a,b;
    cin>>t;
    while(t--)
    { cin>>n>>m;
        REP(i,m)
        {
            cin>>a>>b;
            addEdge(a,b);
        }
            dis=-1; 
         dfs(1,0);

        REP(i,n)
            vis[i]=0;
        
      dis=-1;
      dfs(max_node,0);
      cout<<"Maximum distance : "<<dis<<" ,and the node will be : "<<max_node;
    }

    
}
