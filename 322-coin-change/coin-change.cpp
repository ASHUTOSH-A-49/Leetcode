class Solution {
public:
//TABULATION (BOTTOM - UP) with SPACE OPTIMIZ'n
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<int> dp(amount+1,1e6);
       //base case;
       dp[0] = 0;
       for(int idx = n-1;idx>=0;idx--){
        for(int t = 0;t<=amount;t++){
            int skip = dp[t];
            int take = 1e6;
            if(t>=coins[idx]) take =1+ dp[t-coins[idx]];
            dp[t] = min(take,skip);
        }
       }
       return (dp[amount]>=1e6)?-1 : dp[amount];

    }
};