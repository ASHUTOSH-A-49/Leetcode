class Solution {
public:
vector<vector<vector<int>>> dp;
    bool solve(vector<vector<char>> & g,int i,int j,int l,int &m,int &n){
        if(i>=m || j>=n) return false;
        char c = g[i][j];
        (c=='(') ? l++ : l--;
        if(i==m-1 && j==n-1) {
            return (l==0) ? true : false; 
        }
        if(l<0) return false;
        if(dp[i][j][l]!=-1) return dp[i][j][l];
        bool r = solve(g,i,j+1,l,m,n);
        bool d = solve(g,i+1,j,l,m,n);
        return dp[i][j][l] = (d | r);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(grid[0][0]==')') return false;
        int m = grid.size(),n = grid[0].size();
        int k = m+n;
        dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
        
        return solve(grid,0,0,0,m,n);
    }
};