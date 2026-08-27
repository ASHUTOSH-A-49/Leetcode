class Solution {
public:
// Tabulation -BOTTOM UP 
    int cherryPickup(vector<vector<int>>& g) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = g.size(),m = g[0].size();
        vector<vector<int>> front(m, vector<int>(m, -1));
        vector<vector<int>> curr(m, vector<int>(m, -1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    if (i == n - 1) {
                        if (j1 == j2) curr[j1][j2] = g[i][j1];
                        else curr[j1][j2] = g[i][j1] + g[i][j2];
                    } else {
                        int rmax = -1;
                        for (int dj1 = -1; dj1 < 2; dj1++) {
                            for (int dj2 = -1; dj2 < 2; dj2++) {
                                int c1 = j1 + dj1, c2 = j2 + dj2;
                                if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m) continue;
                                if (front[c1][c2] != -1) {
                                    if (j1 == j2) {
                                        rmax = max(rmax, g[i][j1] + front[c1][c2]);
                                    } else {
                                        rmax = max(rmax, g[i][j1] + g[i][j2] + front[c1][c2]);
                                    }
                                }
                            }
                        }
                        curr[j1][j2] = rmax;
                    }
                }
            }
            // Move the current row configurations to serve as the 'front' for row i-1
            front = curr;
        }
        // At the end of the loop, front holds the final results for row 0
        return front[0][m - 1];
    }
};