#include<bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int vis[10001];

void addEdge(int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);

}
void dfs(int i)
{   
    vis[i]=1;
    for(int child:v[i])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
    
}

int main()
{
    int n,m,a,b,count=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {   cin>>a>>b;
        addEdge(a,b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            count++;
        }
    }
   if(count==1 && n-1==m)
   cout<<"yes";
   else
   cout<<"NO";
}




