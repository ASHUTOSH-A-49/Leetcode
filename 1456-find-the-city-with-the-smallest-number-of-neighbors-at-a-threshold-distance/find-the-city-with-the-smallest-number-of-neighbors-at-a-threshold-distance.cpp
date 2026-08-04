class Solution {
public:
//Floyd Warshall's approach
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dis = distanceThreshold;
        vector<vector<int>> G(n,vector<int>(n,1e9));
        for(auto e:edges){
            int u = e[0],v = e[1],w = e[2];
            G[u][v] = w;
            G[v][u] = w;
        }
        for(int i = 0;i<n;i++){
            G[i][i] = 0;
        }
        
        for(int k = 0;k<n;k++){
            //via k
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if (G[i][k] < 1e9 && G[k][j] < 1e9) {
                        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                    }
                }
            }
        }
        
        int node = -1,city = n+1;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(G[i][j]<=dis) cnt++;
            }
            if(cnt<=city){
                city = cnt;
                node = i;
            }
        }
        return node;
    }
};