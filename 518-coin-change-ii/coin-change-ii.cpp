class Solution {
public:
//TABULATION (BOTTOM - UP)
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(n+1,vector<unsigned int>(amount+1,0));
        //base cases
        for(int i = 0;i<=n;i++)
        dp[i][0] = 1;
        for(int idx = n-1;idx>=0;idx--){
            for(int a = 0;a<=amount;a++){
                unsigned int take = 0;
                unsigned int skip = dp[idx+1][a];
                if(a>=coins[idx]) take = dp[idx][a-coins[idx]];
                dp[idx][a] = take+skip;
            }
        }
        return dp[0][amount];

    }
};