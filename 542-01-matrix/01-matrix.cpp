#define maxi 1e8
class Solution {
public:


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r + 1 < m && ans[r + 1][c] == -1) { ans[r + 1][c] = ans[r][c] + 1; q.push({r + 1, c}); }
            if (r - 1 >= 0 && ans[r - 1][c] == -1) { ans[r - 1][c] = ans[r][c] + 1; q.push({r - 1, c}); }
            if (c + 1 < n && ans[r][c + 1] == -1) { ans[r][c + 1] = ans[r][c] + 1; q.push({r, c + 1}); }
            if (c - 1 >= 0 && ans[r][c - 1] == -1) { ans[r][c - 1] = ans[r][c] + 1; q.push({r, c - 1}); }
        }
        return ans;
    }
};