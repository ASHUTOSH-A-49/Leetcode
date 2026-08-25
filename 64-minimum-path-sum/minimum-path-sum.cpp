class Solution {
public:
    //TABULATION (BOT-UP) SOLUTION
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int dp[m][n];
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(i==m-1&&j==n-1) continue;
                int r = INT_MAX,d = INT_MAX;
                if(i+1<m) r = dp[i+1][j];
                if(j+1<n) d = dp[i][j+1];
                dp[i][j] = grid[i][j]+min(r,d);
            }
        }
        return dp[0][0];
    }
};