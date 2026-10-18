class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int r = 0,c = 0;
        vis[0][0] = true;
        while(true){
            char d = grid[r][c];
            int newr = r,newc = c;
            newr+=(d=='D')?1:0;
            newr+=(d=='U')?-1:0;
            newc+=(d=='R')?1:0;
            newc+=(d=='L')?-1:0;
            if(newr==m || newc==n || newr<0 || newc<0 || vis[newr][newc]){
                break;
            }
            
            r = newr;c = newc;
            vis[r][c] = true;
        }
        return {r,c};
    }
};