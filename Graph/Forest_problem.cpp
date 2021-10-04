#include<bits/stdc++.h>
using namespace std;

string ar[31][31];
int vis[31][31];
int dis[31][31];
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

isValid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m)
    return false;
    if(vis[x][y]==1 || ar[x][y]=="T")
    return false;
    return true;

}

void bfs(int srcX,int srcY)
{
    vis[srcX][srcY]=1;
    dis[srcX][srcY]=0;
    queue<pair<int,int>> q;
    q.push({srcX,srcY});

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        int d=dis[x][y];
        q.pop();

        for(int i=0;i<4;i++)
        {
            int newX=x+dx[i];
            int newY=y+dy[i];

            if(isValid(newX,newY))
            {
                dis[newX][newY]=d+1;
                vis[newX][newY]=1;
                q.push({newX,newY});
            }
        }

    }
}

int main()
{
    cin>>n>>m;
    int srcX,srcY,endX,endY;

    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ar[i][j];
            if(ar[i][j]=="S")
                srcX=i,srcY=j;
            if(ar[i][j]=="E")
                endX=i,endY=j;
                }
            }

    bfs(srcX,srcY);
    if(dis[endX][endY]>0)
    cout<<"Possible";
    else
    cout<<"Not Possible";
}