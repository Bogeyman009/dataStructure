#include <bits/stdc++.h>
using namespace std;
#define n 4


 // } Driver Code Ends
// User function template for C++

    
    vector<string> v;
        
    void dfs(int i,int j,string s,int m[n][n],vector<vector<int>> &vis){
        if(i<0 or j<0 or i>n or j>n) return;
        if(m[i][j]==0 or vis[i][j]==1) return;
        if(i=n-1 and j==n-1){
            v.push_back(s);
            return;
        }
        vis[i][j]=1;
        
        dfs(i-1,j,s+"U",m,n,vis);
        dfs(i+1,j,s+"D",m,n,vis);
        dfs(i,j-1,s+"L",m,n,vis);
        dfs(i,j+1,s+"R",m,n,vis);
        
        vis[i][j]=0;
    }
    vector<string> findPath(int m[n][n],) {
        // Your code goes here
        v.clear();
        vector<vector<int>> vis(MAX,vector<int>(MAX));
        if(m[0][0]==0) return v;
        if(m[n-1][n-1]==0) return v;
        string s="";
        
        dfs(0,0,s,m,n,vis);
        sort(v.begin(),v.end());
        return v;
    }

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;