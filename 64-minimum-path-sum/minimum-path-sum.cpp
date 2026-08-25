class Solution {
public:
    //TABULATION (BOT-UP) SOLUTION with space Optimis'n
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<int> dp(n,INT_MAX);
        dp[n-1] = grid[m-1][n-1];
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(i==m-1&&j==n-1) continue;
                int r = INT_MAX,d = INT_MAX;
                if(j!=n-1) r = dp[j+1];
                d = dp[j];
                dp[j] = grid[i][j]+min(r,d);
            }
        }
        return dp[0];
    }
};