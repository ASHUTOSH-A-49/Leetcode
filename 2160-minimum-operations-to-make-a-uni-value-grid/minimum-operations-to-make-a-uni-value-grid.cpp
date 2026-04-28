class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int cntodd = 0;
        int cnteven = 0;
        int m = grid.size(),n = grid[0].size();
        vector<int> arr (m*n);
        for(int i  = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                arr[i*n+j] = grid[i][j];
            }
        }
        int base_val = arr[0];
        for (int num : arr) {
            if (abs(num - base_val) % x != 0) {
                return -1;
            }
        }
        sort(arr.begin(), arr.end());
        int median = arr[(m * n) / 2];
        int operations = 0;
        for (int num : arr) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};