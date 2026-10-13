class Solution {
public:


    // int solve(int i, int j, string &s) {
    //     if (i >= j) return 0;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     if (s[i] == s[j])
    //         return dp[i][j] = solve(i + 1, j - 1, s);

    //     return dp[i][j] = 1+min(
    //         solve(i + 1, j, s),
    //         solve(i, j - 1, s)
    //     );
    // }
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