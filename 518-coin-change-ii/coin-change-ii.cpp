class Solution {
public:
//TABULATION (BOTTOM - UP) WITH SPACE OPTIMIZ'N
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int> dp(amount+1,0);
        //base cases
        dp[0] = 1;
        for(int idx = n-1;idx>=0;idx--){
            for(int a = 0;a<=amount;a++){
                unsigned int take = 0;
                if(a>=coins[idx]) take = dp[a-coins[idx]];
                dp[a] = take+dp[a];
            }
        }
        return dp[amount];

    }
};