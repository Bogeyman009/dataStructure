#define INF 1000000000
#define vi vector<int>
#define endl '\n'



#include<bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int vis[10001];
int dis[10001];

void addEdge(int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);

}
void dfs(int i,int d)
{
    vis[i]=1;
    dis[i]=d;
    for(int child:v[i])
        if(!vis[child])
            dfs(child,dis[i]+1);
}

int main()
{
    int n,q,a,b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {   cin>>a>>b;
        addEdge(a,b);
    }
    dfs(1,0);
    cin>>q;

int ans= -1 , min_dis=INF;

    while(q--)
    {
       int girl_city;
       cin>>girl_city;
       if(dis[girl_city]<min_dis)
          { 
         min_dis=dis[girl_city];
         ans=girl_city;
        }
        else
        if(dis[girl_city]==min_dis && girl_city<ans)
            ans=girl_city;
    }
    cout<<ans;
}




