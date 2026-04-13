class Solution {
public:
int solve(int a,int b,int m,int n,vector<vector<int>>& maze,
    vector<vector<int>>& dp){
        
        if (a >= m || b >= n || maze[a][b] == 1) {
            return 0;
        }
        if (a == m - 1 && b == n - 1) {
            return 1;
        }

        if (dp[a][b] != -1) {
            return dp[a][b];
        }
        int right = solve(a, b + 1, m, n, maze, dp);
        int down = solve(a + 1, b, m, n, maze, dp);
        return dp[a][b] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0, 0, m, n, obstacleGrid, dp);
    }
};