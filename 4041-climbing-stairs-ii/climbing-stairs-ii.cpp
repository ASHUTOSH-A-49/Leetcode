class Solution {
public:
int dp[100001];
int INF = 1e9;
int solve(int i,int &n,vector<int> & costs){
    if (i >= n) return 0;
    if(dp[i]!=-1) return dp[i];
    int j1 = 1e9,j2 = 1e9,j3 = 1e9;
    if(i+1<=n) j1 = solve(i+1,n,costs) + 1 + costs[i];
    if(i+2<=n) j2 = solve(i+2,n,costs)  + 4 + costs[i+1];
    if(i+3<=n) j3 = solve(i+3,n,costs)  + 9 + costs[i+2];
    return dp[i] = min(j1,min(j2,j3));
}
    int climbStairs(int n, vector<int>& costs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        memset(dp,-1,sizeof(dp));
        return solve(0,n,costs);
    }
};