class Solution {
public:
using ll = long long;
int MOD = 1e9+7;
vector<vector<vector<int>>> dp;
int solve(int i,int j,vector<vector<int>>& grid, int prev){
    int m = grid.size(),n = grid[0].size();
    if(i==m-1 && j==n-1) return 1;
    if(i==m || j==n) return 0;
    bool mirr = (grid[i][j]==1);
    if(dp[i][j][mirr]!=-1) return dp[i][j][mirr];
    if(mirr){
        // 0 means right enter and 1 means left enter
        if(prev==0) return solve(i+1,j,grid,1)%MOD;
        if(prev==1) return solve(i,j+1,grid,0)%MOD;
    }
    int r=0,d=0;
    r = solve(i,j+1,grid,0)%MOD;
    d = solve(i+1,j,grid,1)%MOD;
    return dp[i][j][mirr] = (r+d)%MOD;
    
}
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(2,-1)));
        if(grid[m-1][n-1]==1) return 0;
        return solve(0,0,grid,-1)%MOD;
    }
};