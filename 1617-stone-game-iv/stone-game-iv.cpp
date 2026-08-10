class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);
        dp[1] = true;
        //dp[i] = is ith state a winning state? i.e. if player starts with i stones and they play can player win ?
        for(int i = 2;i<=n;i++){
            for(int j = 1;j*j<=i;j++){
                int sq = j*j;
                // if after removing sq stones, the state ends in a losing state then we declare current state to be winning state
                if(!dp[i-sq]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};