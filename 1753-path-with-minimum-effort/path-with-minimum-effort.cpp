class Solution {
public:
    // DIJKSTRA's approach
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size(), m = heights[0].size(); 
        vector<vector<int>> dist(n, vector<int>(m, 1e7)); 
        dist[0][0] = 0;
        
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> st; 
        st.push({0, {0, 0}}); 
        
        int drow[] = {-1,1,0,0}; 
        int dcol[] = {0,0,-1,1}; 
        
        while(!st.empty()){ 
            auto p = st.top(); 
            int d = p.first, r = p.second.first, c = p.second.second; 
            st.pop(); 
            
            if (d > dist[r][c]) continue; 
            
            for(int i = 0; i < 4; i++){ 
                int nr = r + drow[i]; 
                int nc = c + dcol[i]; 
                
                if(nr >= 0 && nc >= 0 && nr < n && nc < m) { 
                    int d1 = abs(heights[r][c] - heights[nr][nc]); 
                    int d2 = max(d, d1); 
                    
                    if(d2 < dist[nr][nc]) { 
                        dist[nr][nc] = d2; 
                        st.push({d2, {nr, nc}}); 
                    } 
                } 
            } 
        } 
        
        return dist[n-1][m-1];

    }
};