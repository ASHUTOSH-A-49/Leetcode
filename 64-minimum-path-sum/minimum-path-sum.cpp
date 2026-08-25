class Solution {
public:
    //MEMOIZATION SOLUTION
    int dp[201][201];
    int solve(int i,int j,int m,int n,vector<vector<int>> & g){
        if(i==m || j==n) return INT_MAX;
        if(i==m-1 && j==n-1) return g[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int r = solve(i,j+1,m,n,g);
        int d = solve(i+1,j,m,n,g);
        return dp[i][j] = g[i][j]+min(r,d);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n,grid);
    }
};