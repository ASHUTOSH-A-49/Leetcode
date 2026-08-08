class Solution {
public:
int timer = 1;
    void DFS(int node,int par, vector<int> & vis,vector<vector<int>> & G,vector<int> & tin, vector<int> & low,vector<vector<int>> & bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto i:G[node]){
            if(i==par) continue; //all except parent
            if(vis[i]){
                low[node] = min(low[node],low[i]);
            }else{
                // if not visited first DFS visits them 
                DFS(i,node,vis,G,tin,low,bridges);
                low[node] = min(low[node],low[i]);

                if(low[i]>tin[node]) {
                    // then it can't reach its adj i.e. bridge 
                    bridges.push_back({node,i});
                }
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> G(n);
        for(auto c:connections){
            int u = c[0],v = c[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector<int> vis(n,0);
        vector<int> tin(n),low(n);
        vector<vector<int>> bridges;
        DFS(0,-1,vis,G,tin,low,bridges);
        return bridges;
    }
};