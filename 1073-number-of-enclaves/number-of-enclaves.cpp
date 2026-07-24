class Solution {
public:
// BFS SOLUTION 
int BFS(vector<vector<int>> & grid,vector<vector<int>> & visited,int i,int j){
    if(grid[i][j]==0||visited[i][j])return 0;
    queue<pair<int,int>>q;
    q.push({i,j});
    visited[i][j]=1;
    int cnt=0;
    int m=grid.size(),n=grid[0].size();
    while(!q.empty()){
        int siz=q.size();
        for(int k=0;k<siz;k++){
            auto p=q.front();
            q.pop();
            int r=p.first,c=p.second;
            if(grid[r][c]==1)cnt++;
            if(r+1<m&&!visited[r+1][c]&&grid[r+1][c]==1){visited[r+1][c]=1;q.push({r+1,c});}
            if(r-1>=0&&!visited[r-1][c]&&grid[r-1][c]==1){visited[r-1][c]=1;q.push({r-1,c});}
            if(c+1<n&&!visited[r][c+1]&&grid[r][c+1]==1){visited[r][c+1]=1;q.push({r,c+1});}
            if(c-1>=0&&!visited[r][c-1]&&grid[r][c-1]==1){visited[r][c-1]=1;q.push({r,c-1});}
        }
    }
    return cnt;
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int tot1 = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));

        //BOUNDARY TRAVERSAL DFS
        for(auto v:grid){
            for(int i:v){
                if(i==1) tot1++;
            }
        }
        if(m==1){
            for(int j=0;j<n;++j){
                tot1 -=BFS(grid,visited,0,j);
            }
        }
        if(n==1){
            for(int i=0;i<m;++i){
                tot1 -=BFS(grid,visited,i,0);
            }
        }
        for(int j=0;j<n;++j){
            tot1 -=BFS(grid,visited,0,j);
        }
        // leave first row
        for(int i=1;i<m;++i){
            tot1 -=BFS(grid,visited,i,n-1);
        }
        // leave last col
        for(int j=n-2;j>=0;--j){
            tot1 -=BFS(grid,visited,m-1,j);
        }
        // leave last row
        for(int i=m-2;i>0;--i){
            tot1 -=BFS(grid,visited,i,0);
        }

        return tot1;

    }
};