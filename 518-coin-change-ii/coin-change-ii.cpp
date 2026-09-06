class Solution {
public:
int dp[301][5001];
    int solve(int idx,vector<int> & coins, int target, int &n){
        if(target<0) return 0;
        if(idx==n){
            return (target==0)? 1 : 0;
        }
        if(target<0) return 1e6;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int take = solve(idx,coins,target-coins[idx],n);
        int skip = solve(idx+1,coins,target,n);
        return dp[idx][target]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int n = coins.size();
       int res= solve(0,coins,amount,n);
       return res;

    }
};