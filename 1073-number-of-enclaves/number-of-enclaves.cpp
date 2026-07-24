class Solution {
public:
int DFS(vector<vector<int>> & grid,vector<vector<int>> & visited,int i,int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
    if(visited[i][j]) return 0;
    if(grid[i][j]==0) return 0;
    visited[i][j] = 1;
    return 1 + (
        DFS(grid,visited,i,j+1)+
        DFS(grid,visited,i,j-1)+
        DFS(grid,visited,i+1,j)+
        DFS(grid,visited,i-1,j)
    );
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int tot1 = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(auto v:grid){
            for(int i:v){
                if(i==1) tot1++;
            }
        }
        if(m==1){
            for(int j=0;j<n;++j){
                tot1 -=DFS(grid,visited,0,j);
            }
        }
        if(n==1){
            for(int i=0;i<m;++i){
                tot1 -=DFS(grid,visited,i,0);
            }
        }
        for(int j=0;j<n;++j){
            tot1 -=DFS(grid,visited,0,j);
        }
        for(int i=1;i<m;++i){
            tot1 -=DFS(grid,visited,i,n-1);
        }
        for(int j=n-2;j>=0;--j){
            tot1 -=DFS(grid,visited,m-1,j);
        }
        for(int i=m-2;i>0;--i){
            tot1 -=DFS(grid,visited,i,0);
        }

        return tot1;

    }
};