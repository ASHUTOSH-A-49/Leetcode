class Solution {
public:
// TABULATION APPROACH
    int numDistinct(string s, string t) {
        if(s.size()<t.size()) return 0;
        int m = s.size(),n = t.size();
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));
        for(int j= 0;j<=n;j++){
            dp[m][j] = 0;
        }
        for(int i = 0;i<=m;i++){
            dp[i][n] = 1;
        }
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j]+=dp[i+1][j+1];
                }
                dp[i][j]+=dp[i+1][j];
            }
        }
        
        return dp[0][0];
    }
};