#include<bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int vis[10001];
int col[100001];

void addEdge(int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);

}

bool dfs(int i,int c)
{
    vis[i]=1;
    col[i]=c;
    for(int child:v[i])
        {
            if(!vis[child])
        {
        bool res=dfs(child,c^1);
            if(res == false)
                return false;
        }
        if(col[child]==col[i])
        return  false;
        }
        return true;
}

int main()
{
    int t,n,m,a,b;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) 
        {
            v[i].clear();
            vis[i]=0;
            col[i]=0;
        }

        for(int i=1;i<=m;i++)
        {       cin>>a>>b;
            addEdge(a,b);
        }
        bool flag=true;

        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                bool res=dfs(i,0);
                if(res==false)
                    flag=false;
                }
        }
        cout<<"Scenario #"<<tc<<": ";
        if(flag==false)
        cout<<"suspicious";
        else
        cout<<"Not Suspicious";

    }
}