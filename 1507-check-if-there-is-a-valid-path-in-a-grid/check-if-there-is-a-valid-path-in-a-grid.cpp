class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int dirs[7][2][2] = {
            {{0,0}, {0,0}},
            {{0,-1}, {0,1}},
            {{-1,0}, {1,0}},
            {{0,-1}, {1,0}},
            {{0,1}, {1,0}},
            {{0,-1}, {-1,0}},
            {{0,1}, {-1,0}}
        };

        auto can_connect = [&](int r, int c, int pr, int pc) {
            if (r < 0 || r >= m || c < 0 || c >= n) return false;
            int street = grid[r][c];
            for (int i = 0; i < 2; i++) {
                if (r + dirs[street][i][0] == pr && c + dirs[street][i][1] == pc) return true;
            }
            return false;
        };

        auto solve = [&](int start_dir_idx) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int r = 0, c = 0;
            int street = grid[0][0];
            
            int dr = dirs[street][start_dir_idx][0];
            int dc = dirs[street][start_dir_idx][1];
            
            while (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {
                visited[r][c] = true;
                if (r == m - 1 && c == n - 1) return true;

                int nr = r + dr;
                int nc = c + dc;

                if (can_connect(nr, nc, r, c)) {
                    int n_street = grid[nr][nc];
                    for (int i = 0; i < 2; i++) {
                        int next_dr = dirs[n_street][i][0];
                        int next_dc = dirs[n_street][i][1];
                        if (nr + next_dr != r || nc + next_dc != c) {
                            dr = next_dr;
                            dc = next_dc;
                            break;
                        }
                    }
                    r = nr;
                    c = nc;
                } else {
                    break;
                }
            }
            return false;
        };

        return solve(0) || solve(1);
    }
};