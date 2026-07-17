class Solution {
public:
void DFS(vector<vector<char>> &grid,vector<vector<int>> &visited,int sr,int sc){
    if(sr>=grid.size() || sc>=grid[0].size()) return;
    if(visited[sr][sc]) return;
    if(grid[sr][sc]=='0') return;
    visited[sr][sc] = 1;
    DFS(grid,visited,sr,sc+1); //right
    // DFS(grid,visited,sr+1,sc+1); //if asked diagonally too then (bot right diag)
    DFS(grid,visited,sr+1,sc); //down
    DFS(grid,visited,sr-1,sc); //up
    DFS(grid,visited,sr,sc-1); //right
    return;
}
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size(), cnt = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!visited[i][j] && grid[i][j]!='0'){
                    DFS(grid,visited,i,j);
                    cnt++;
                } 
            }
        }
        return cnt;
    }
};