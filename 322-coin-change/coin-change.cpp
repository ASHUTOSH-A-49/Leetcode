class Solution {
public:
//TABULATION (BOTTOM - UP)
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();

       vector<vector<int>> dp(n+1,vector<int>(amount+1,1e6));
       //base case;
       dp[n][0] = 0;
       for(int idx = n-1;idx>=0;idx--){
        for(int t = 0;t<=amount;t++){
            int skip = dp[idx+1][t];
            int take = 1e6;
            if(t>=coins[idx]) take =1+ dp[idx][t-coins[idx]];
            dp[idx][t] = min(take,skip);
        }
       }
       return (dp[0][amount]>=1e6)?-1 : dp[0][amount];

    }
};