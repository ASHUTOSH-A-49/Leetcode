class Solution {
public:
void simplerotate(vector<vector<char>>& boxGrid,vector<vector<char>> &ans,int m,int n){
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            ans[j][m - 1 - i] = boxGrid[i][j];
        }
    }
    
}
void conditions(vector<vector<char>> &ans, int n, int m) {
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (ans[i][j] == '#') {
                int k = i + 1;
                while (k < n && ans[k][j] == '.') {
                    k++;
                }
                if (k - 1 != i) {
                    ans[k - 1][j] = '#';
                    ans[i][j] = '.';
                }
            }
        }
    }
}

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> ans(n,vector<char> (m));
        simplerotate(boxGrid,ans,m,n);
        conditions(ans,n,m);
        return ans;
    }
};