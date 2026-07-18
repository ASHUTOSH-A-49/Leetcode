class Solution {
public:
    int BFS(vector<vector<int>> & grid, queue<pair<int,int>> & q, int fresh){ 
        if (fresh == 0) return 0;
        int m = grid.size(), n = grid[0].size(); 
        int t = 0; 
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty() && fresh > 0){ 
            int s = q.size(); 
            t++; 
            for(int k = 0; k < s; k++){ 
                auto [i, j] = q.front(); 
                q.pop(); 
                for(int d = 0; d < 4; d++){ 
                    int r = i + dirs[d][0]; 
                    int c = j + dirs[d][1]; 
                    if(r >= 0 && c >= 0 && r < m && c < n && grid[r][c] == 1) { 
                        grid[r][c] = 2; 
                        q.push({r, c}); 
                        fresh--; 
                    } 
                } 
            } 
        } 
        return fresh == 0 ? t : -1; 
    } 

    int orangesRotting(vector<vector<int>>& grid) { 
        int m = grid.size(), n = grid[0].size(); 
        queue<pair<int,int>> q; 
        int fresh = 0;
        for(int i = 0; i < m; i++){ 
            for(int j = 0; j < n; j++){ 
                if(grid[i][j] == 2) q.push({i, j}); 
                else if(grid[i][j] == 1) fresh++;
            } 
        } 
        return BFS(grid, q, fresh); 
    } 
};