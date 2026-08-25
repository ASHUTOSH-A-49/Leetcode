class Solution {
public:
// TABULATION approach (BOTTOM UP)
    int minimumTotal(vector<vector<int>>& triangle) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = triangle.size();
        vector<int> dp(n);
        for(int i = 0;i<n;i++){
            dp[i] = triangle[n-1][i];
        }
        int siz = n-2;
        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<=siz;j++){
                dp[j] = triangle[i][j]+min(dp[j],dp[j+1]);
            }
            siz--;
        }
        return dp[0];
    }
};