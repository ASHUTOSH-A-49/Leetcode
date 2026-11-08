class Solution {
public:
int cnt = 0;
    int BFS(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, int &m, int &n, int dir) {
        if (i == m || j == n) return 0;
        int serv = (grid[i][j] == 1) ? 1 : 0;
        if (serv) vis[i][j] = 1; 
        if (dir == 1) { 
            return serv + BFS(grid, vis, i + 1, j, m, n, dir);
        }
        return serv + BFS(grid, vis, i, j + 1, m, n, dir);
    }
    
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> counted(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (counted[i][j] || grid[i][j] != 1) continue;
                
                vector<vector<int>> visCol(m, vector<int>(n, 0));
                vector<vector<int>> visRow(m, vector<int>(n, 0));
                int colServers = BFS(grid, visCol, 0, j, m, n, 1);
                int rowServers = BFS(grid, visRow, i, 0, m, n, 0);
                int bfsres = colServers + rowServers - 2; 
                if (bfsres > 0) {
                    cnt += 1;
                    counted[i][j] = 1;
                    for (int r = 0; r < m; r++) {
                        for (int c = 0; c < n; c++) {
                            if (visCol[r][c] || visRow[r][c]) {
                                if (!counted[r][c]) {
                                    cnt++;
                                    counted[r][c] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};