class Solution {
public:
vector<vector<vector<int>>> dp;
int solve(int i,int j,int current_xor,vector<vector<int>> & grid){
    int m = grid.size(),n = grid[0].size();
    if(i==m || j==n) return INT_MAX;
    int next_xor = current_xor^grid[i][j];
    if(i==m-1 && j==n-1) return next_xor;
    if(dp[i][j][current_xor]!=-1) return dp[i][j][current_xor];
    int r = solve(i,j+1,next_xor,grid);
    int d = solve(i+1,j,next_xor,grid);
    return dp[i][j][current_xor] = min(r,d);
}
int minCost(vector<vector<int>>& grid) {
    int m = grid.size(),n = grid[0].size();
    dp.assign(m,vector<vector<int>>(n,vector<int>(1024,-1)));
    return solve(0,0,0,grid);
}
};