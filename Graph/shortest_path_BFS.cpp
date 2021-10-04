#define REP(i,n) for(int i=1;i<=n;i++)
#define mod 1000000007
#define vi vector<int>

#include<bits/stdc++.h>
using namespace std;

vi v[10001];
int vis[10001];
int dis[10001];

void addEdge(int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
}

void bfs(int i)
{
    queue<int> q;
    q.push(i);
    vis[i]=1;
    dis[i]=0;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        for(int child:v[u])
            if(!vis[child])
            {
                q.push(child);
                dis[child]=dis[u]+1;
                vis[child]=1;
            }
    }
}

int main()
{
    int t,n,m,a,b;
    cin>>t;
    while(t--)
    {  cin>>n>>m;
    REP(i,n)
            {
                v[i].clear();
                vis[i]=0;
            }
        REP(i,m)
        {
            cin>>a>>b;
            addEdge(a,b);
        }
        
        bfs(1);

        cout<<dis[n];
    }

}