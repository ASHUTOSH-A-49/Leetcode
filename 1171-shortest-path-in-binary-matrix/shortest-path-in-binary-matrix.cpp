class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        if(n==1) return (grid[0][0]) ? -1:1;
        if(grid[0][0]) return -1;
        set<pair<int,pair<int,int>>> st;
        st.insert({!grid[0][0],{0,0}});
        while(!st.empty()){
            auto [d1,p] = *st.begin();
            auto [i,j] = p;
            st.erase(st.begin());
            if(d1>dist[i][j]) continue;
            int drow[] = {-1,0,1};
            int dcol[] = {-1,0,1};
            for(int r :drow){
                for(int c:dcol){
                    int row = r+i,col = c+j;
                    if(row>=0 && col>=0 && row<n && col<n){
                        if(row==i && col==j) continue;
                        if(d1+!grid[row][col] < dist[row][col] && grid[row][col]==0){
                            dist[row][col] = d1+!grid[row][col];
                            st.insert({dist[row][col],{row,col}});
                        }
                    }
                }
            }
            
        }
        return (dist[n-1][n-1]==INT_MAX) ? -1:dist[n-1][n-1];

    }
};