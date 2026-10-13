class Solution {
public:
    // tabulation
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<n;j++){
                if(i>=j) continue;
                if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = 1+min(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};