class Solution {
public:
int solve(int a,int b,int m,int n,vector<vector<int>>& maze,
    int cnt,int target){
        
        if (a<0 || b<0 || a >= m || b >= n || maze[a][b] == -1 || maze[a][b]==3) {
            return 0;
        }
        if (maze[a][b]==2) {
            if(cnt==target)
            return 1;
            return 0;
        }
        int temp = maze[a][b];
        maze[a][b] = 3;
        
        int paths = 0;
        paths += solve(a + 1, b, m, n, maze, cnt + 1, target);
        paths += solve(a - 1, b, m, n, maze, cnt + 1, target);
        paths += solve(a,b + 1, m, n, maze, cnt + 1, target);
        paths += solve(a, b - 1, m, n, maze, cnt + 1, target);

        maze[a][b] = temp; // (backtrack)
        
        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int empcell = 0,startr,startc;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]!=-1) empcell++;
                if(grid[i][j]==1){
                    startr = i;startc = j;
                }
            }
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(startr,startc, m, n, grid,1,empcell);
    }
};