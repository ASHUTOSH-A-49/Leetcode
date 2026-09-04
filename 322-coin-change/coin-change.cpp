class Solution {
public:
int dp[12][10001];
    int solve(int idx,vector<int> & coins, int target, int &n){
        if(idx==n){
            return (target==0)? 0 : 1e6;
        }
        if(target<0) return 1e6;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int take = 1+solve(idx,coins,target-coins[idx],n);
        int skip = solve(idx+1,coins,target,n);
        return dp[idx][target]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int n = coins.size();
       int res= solve(0,coins,amount,n);
       return (res==1e6) ? -1:res;

    }
};