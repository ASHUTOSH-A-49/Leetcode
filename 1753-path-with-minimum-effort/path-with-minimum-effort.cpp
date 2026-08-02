class Solution {
public:
    
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size(), m = heights[0].size(); 
        vector<vector<int>> dist(n, vector<int>(m, 1e7)); 
        vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m)); 
        
        dist[0][0] = 0; 
        parent[0][0] = {0,0}; 
        
        set<pair<int,pair<int,int>>> st; 
        st.insert({0, {0, 0}}); 
        
        int drow[] = {-1,1,0,0}; 
        int dcol[] = {0,0,-1,1}; 
        
        while(!st.empty()){ 
            auto p = *st.begin(); 
            int d = p.first, r = p.second.first, c = p.second.second; 
            st.erase(st.begin()); 
            
            if (d > dist[r][c]) continue; 
            
            for(int i = 0; i < 4; i++){ 
                int nr = r + drow[i]; 
                int nc = c + dcol[i]; 
                
                if(nr >= 0 && nc >= 0 && nr < n && nc < m) { 
                    int edgeEffort = abs(heights[r][c] - heights[nr][nc]); 
                    int newEffort = max(d, edgeEffort); 
                    
                    if(newEffort < dist[nr][nc]) { 
                        if(dist[nr][nc] != 1e7){ 
                            st.erase({dist[nr][nc], {nr, nc}}); 
                        } 
                        
                        dist[nr][nc] = newEffort; 
                        parent[nr][nc] = {r, c}; 
                        st.insert({newEffort, {nr, nc}}); 
                    } 
                } 
            } 
        } 
        
        for(int i = 0; i < n; i++){ 
            for(int j = 0; j < m; j++){ 
                auto p = parent[i][j]; 
                cout << p.first << " " << p.second << "\t"; 
            } 
            cout << endl; 
        } 
        
        int maxd = 0; 
        int r1 = n-1, c1 = m-1; 
        
        if (n == 1 && m == 1) return 0; 
        
        while(true){ 
            auto p = parent[r1][c1]; 
            int r2 = p.first, c2 = p.second; 
            
            maxd = max(maxd, abs(heights[r1][c1] - heights[r2][c2])); 
            
            if(r2 == 0 && c2 == 0){ 
                break; 
            } 
            r1 = r2; 
            c1 = c2; 
        } 
        return maxd; 

    }
};