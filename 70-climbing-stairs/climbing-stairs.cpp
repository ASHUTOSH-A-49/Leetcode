class Solution {
public:
// int dp[50];
// //memoization (top-down)
//     int solve(int i,int n){
//         if(dp[i]!=-1) return dp[i];
//         if(i>n) return 0;
//         if(i==n){
//             return 1;
//         }
//         return dp[i] = solve(i+1,n) +
//         solve(i+2,n);

//     }
    int climbStairs(int n) {
        //tabulation  (bottom up)
        int dp[n+1];
        dp[n] = 1;
        dp[n-1] = 2;
        for(int i = n-2;i>0;i--){
            dp[i] = dp[i+1]+dp[i+2];
        }
        return dp[1];
        
    }
};