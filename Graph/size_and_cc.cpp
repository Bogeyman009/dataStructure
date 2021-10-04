//to count the no of connected component and count the member in each component;


#define REP(i,n) for(int i=1;i<=n;i++)
#define mod 1000000007
#define vi vector<int>

#include<bits/stdc++.h>
using namespace std;

vi v[10001];
int vis[10001];
int cc_size;

void addEdge(int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
}

void dfs(int i)
{
    vis[i]=1;
    cc_size++;
    for(int child:v[i])
        if(!vis[child])
            dfs(child);
}

int main()
{
    int t,n,m,a,b;
    cin>>t;
    while(t--)
    { int count=0;
        cin>>n>>m;
        long long int res=1;

        REP(i,n)
        {
            vis[i]=0;
            v[i].clear();
        }
        
        REP(i,m)
        {
            cin>>a>>b;
            addEdge(a,b);
        }
            REP(i,n)
            {
                if(vis[i]==0)
                {
                    cc_size=0;
                    dfs(i);
                    count++;
                    res=(res*cc_size)%mod;
                }
            }
            cout<<count<<" "<<res<<endl;
        
    }
}
