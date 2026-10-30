class Solution {
public:
//TABULATION APPROACH
    int minDistance(string word1, string word2) {
        int m = word1.size(),n = word2.size();
        vector<vector<int>> dp;
        dp.assign(m+1,vector<int>(n+1,-1));
        for(int i = 0;i<m;i++){
            dp[i][n] = m-i;
        }
        for(int j = 0;j<n;j++){
            dp[m][j] = n-j;
        }
        dp[m][n] = 0;
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                int repl = ((word1[i]==word2[j])?0:1) + dp[i+1][j+1];
                int ins = 1 + dp[i][j+1];
                int del = 1+dp[i+1][j];
                dp[i][j] = min({repl,ins,del});
            }
        }
        return dp[0][0];
    }
};