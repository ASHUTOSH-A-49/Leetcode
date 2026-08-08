class Solution {
public:
int dp[50];
//memoization (top-down)
    int solve(int i,int n){
        if(dp[i]!=-1) return dp[i];
        if(i>n) return 0;
        if(i==n){
            return 1;
        }
        return dp[i] = solve(i+1,n) +
        solve(i+2,n);

    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n);
        
    }
};