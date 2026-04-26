class Solution {
public:
bool solve(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int pi, int pj, int m, int n, char target) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != target) {
            return false;
        }
        if (visited[i][j]) {
            return true;
        }
        visited[i][j] = true;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni == pi && nj == pj) continue;

            if (solve(grid, visited, ni, nj, i, j, m, n, target)) return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (solve(grid, visited, i, j, -1, -1, m, n, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};