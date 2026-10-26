using ll = long long;
class Solution {
public:
    ll solve(vector<vector<int>>& grid, vector<vector<bool>> & vis,int i,int j,int &m,int &n){
        if(i<0 || j<0 ||i==m || j==n) return 0;
        if(vis[i][j]) return 0;
        if(grid[i][j]==0) return 0;
        vis[i][j] = true;
        ll up,down,left,right;
        up = solve(grid,vis,i-1,j,m,n);
        down = solve(grid,vis,i+1,j,m,n);
        left = solve(grid,vis,i,j-1,m,n);
        right = solve(grid,vis,i,j+1,m,n);
        return grid[i][j]+ up+down+left+right;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j] || grid[i][j]==0) continue; 
                ll res = solve(grid,vis,i,j,m,n);
                if(res%k==0) cnt++;
            }
        }
        return cnt;
    }
};