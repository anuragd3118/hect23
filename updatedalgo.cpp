#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define fo(a,b,c) for(int a=b;a<c;a++)
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int func(int i, int j, vector<vector<int>>& adj, vector<vector<int>>& dp, int par){
    // vis[i] = 1;
    int ans = 0, ans1 = 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(j){
        for(auto node1 : adj[i]){
            if(node1 != par)
            ans1 += func(node1, 1, adj, dp, i);
        }
        for(auto node : adj[i]){
            if(node != par)
            ans = max(ans, func(node, 0, adj, dp, i) + ans1 + 1 - dp[node][1]);
        }
    }
    else{
        for(auto node : adj[i]){
            if(node != par)
            ans += func(node, 1, adj, dp, i);
        }
    }
    return dp[i][j] = ans;
}
void code()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n + 1, 0);
    int k = max(func(1, 1, adj, dp, -1), func(1, 0, adj, dp, -1));
    cout << k;
}
int32_t main()
{
    fast
    int test = 1;
    // cin >> test;
    for(int i=0;i<test;i++)
    {
        code();
    }
    return 0;
}
