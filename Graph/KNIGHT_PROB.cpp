#include<bits/stdc++.h>
using namespace std;

string ar[31][31];
int vis[31][31];
int dis[31][31];
int n,m;
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

isValid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m)
    return false;
    if(vis[x][y]==1 || ar[x][y]!="2 1")
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
    
    int srcX,srcY,endX,endY;

    for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
            ar[i][j]="i j";
            if(ar[i][j]=="1 1")
                srcX=i,srcY=j;
            if(ar[i][j]=="2 1")
                endX=i,endY=j;
                }
            }

    bfs(srcX,srcY);
    cout<<dis[endX][endY];
    
}