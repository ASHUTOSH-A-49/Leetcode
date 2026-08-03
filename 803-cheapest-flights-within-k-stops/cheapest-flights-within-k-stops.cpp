class Solution {
public:
// BFS approach
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> G(n);
        for(auto f:flights){
            int u = f[0],v = f[1],p = f[2];
            G[u].push_back({p,v});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        //queue by stops q = {stops,{node,dist}};
        q.push({0,{src,0}});
        k++;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int stop = p.first;
            auto [node,d] = p.second;
            for(auto [d2,i]:G[node]){
                if(stop+1<=k){
                    if(d+d2<dist[i]){
                        dist[i] = d+d2;
                        q.push({stop+1,{i,dist[i]}});
                    }
                }
            }
        }
        return (dist[dst]==1e9) ? -1:dist[dst];
        
    }
};