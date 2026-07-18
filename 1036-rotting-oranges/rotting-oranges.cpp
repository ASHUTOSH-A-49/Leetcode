class Solution {
public:
    int BFS(vector<vector<int>> & grid,queue<pair<int,int>> q){
        int t = 0;
        int m = grid.size(),n = grid[0].size();
        while(!q.empty()){
            int s = q.size();
            
            bool rot = false;
            for(int k = 0;k<s;k++){
                auto p = q.front();
                int i = p.first,j = p.second;
                q.pop();
                for(int r = -1;r<2;r++){
                    for(int c = -1;c<2;c++){
                        if((r==c) || (r==1&&c==-1) || (r==-1 && c==1)) continue;
                        if(i+r<0 || j+c<0 || i+r>=m || j+c>=n) continue;
                        if(grid[i+r][j+c]==1) {
                            grid[i+r][j+c] = 2;
                            q.push({i+r,j+c});
                            rot = true;
                        }
                    }
                }
            }
            if(rot) t++;
        }
        return t;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int t =  BFS(grid,q);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return t;
    }
};