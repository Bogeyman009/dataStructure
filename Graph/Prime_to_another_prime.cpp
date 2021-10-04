#define REP(i,n) for(int i=1;i<=n;i++)
#define mod 1000000007
#define vi vector<int>


#include<bits/stdc++.h>
using namespace std;

vi v[10001];
int vis[10001];
int dis[10001];
vector<int> primes;

bool isPrime(int n)
{
 
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
        
    return true;
}



bool isValid(int a,int b)
{
    int count=0;
    while(a>0)
    {
        if(a%10 != b%10)
        count++;
        a/=10;
        b/=10;

    }
    if(count==1)
    return true;
    return false;
}
void buildGraph()
{
    for(int i=1000;i<=9999;i++)
    {
        if(isPrime(i))
            primes.push_back(i);
    }
        for(int i=0;i<primes.size();i++)
        {
            for(int j=i+1;j<primes.size();j++)
            {
                int a=primes[i];
                int b=primes[j];
                
                if(isValid(a,b))
                {
                    v[a].push_back(b);
                    v[b].push_back(a);
                }
            }
        }
    
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
    int t,a,b;
    cin>>t;
    buildGraph();
    while(t--)
    {
        cin>>a>>b;
        for(int i=1000;i<=9999;i++)
        {
            dis[i]=-1;
            vis[i]=0;
        }
        bfs(a);

        if(dis[b]== -1)
        cout<<"Impossible";
        else
        cout<<dis[b]<<endl;
    }
}