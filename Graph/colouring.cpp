#include<bits/stdc++.h>
using namespace std;

int vis[101][101];
int arr[30][30];
int newcolor;
int n;

bool isValid(int x,int y)
{
    if(x<0 || x>n || y<0 || y>n)
    return false;
    if(vis[x][y]==1 || arr[x][y]==0)
    return false;

    return true;
}
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1}; // U L D R     

void dfs(int sr,int sc)
{
    vis[sr][sc]=1;
    arr[sr][sc]=newcolor;
    for(int i=0;i<4;i++)
            if(isValid(sr+dx[i],sc+dy[i]))
               dfs(sr+dx[i],sc+dy[i]);
}

int main()
{
    n=3;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
int sr,sc;
cin>>sr>>sc;

cin>>newcolor;
int elem=arr[sr][sc];

      dfs(sr,sc);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
            
            cout<<endl;
    }

}
