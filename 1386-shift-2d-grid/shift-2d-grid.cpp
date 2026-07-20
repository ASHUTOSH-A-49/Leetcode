class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        vector<int> flat(m*n);
        int idx = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                flat[idx++] = grid[i][j];
            }
        }
        int mod = m*n;
        vector<int> flat2(mod);
        for(int i = 0;i<mod;i++){
            flat2[(i+k)%mod] = flat[i];
        }
        vector<vector<int>> ans(m,vector<int>(n));
        idx = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                ans[i][j] = flat2[idx++];
            }
        }
        return ans;
    }
};