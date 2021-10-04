#include<bits/stdc++.h>
using namespace std;
int n,m;
string ar[101][101];
int vis[101][101];
int dis;


bool isValid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m)
    return false;
    if(vis[x][y]==1 || ar[x][y]=="#")
    return false;

    return true;
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y)
{
    vis[x][y]=1;
    dis++;
    for(int i=0;i<4;i++)
        if(isValid(x+dx[i],y+dy[i]))
            dfs(x+dx[i],y+dy[i]); 
}

int main()
{   int count=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>ar[i][j];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vis[i][j]==0 && ar[i][j]==".")
           { 
            dfs(i,j);
            count++;
           
            }
        }
    }
        cout<<"Total connected components are :" <<count;
}



/* 
6 6 
0 0 1 0 1 1
0 1 1 0 0 1
0 1 0 0 0 0
1 0 1 1 0 0
0 0 0 1 0 0
0 1 1 0 1 1 
*/