#include<bits/stdc++.h>
using namespace std;

vector <int> arr[100];
vector <int> res;
int in[100];

void khan(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            q.push(i);
    
    while(!q.empty())
    {
        int curr=q.front();
        res.push_back(curr);
        q.pop();
        for(int node:arr[curr])
        {
            in[node]--;
                if(in[node]==0)
                    q.push(node);
        }
    }
    for(int node:res)
    cout<<node<<" ";
}

int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {   cin>>x>>y;
        arr[x].push_back(y);
        in[y]++;
    }
    khan(n);
}