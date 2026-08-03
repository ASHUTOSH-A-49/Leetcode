class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> G(n);
        for(auto f:flights){
            int u = f[0],v = f[1],p = f[2];
            G[u].push_back({p,v});
        }
        set<pair<int,pair<int,int>>> st;
        k++;
        //sort by price
        vector<vector<int>> dist(n,vector<int>(k+2,1e9));
        st.insert({0,{0,src}});
        dist[src][0]=0;
        while(!st.empty()){
            auto p = *st.begin();
            int d = p.first; 
            auto [stop,node] = p.second;
            st.erase(st.begin());
            if(node==dst)return d;
            for(auto [d2,i]:G[node]){
                if(d+d2 < dist[i][0]){
                    if(stop+1<=k){
                    if(d+d2<dist[i][stop+1]){
                        dist[i][stop+1]=d+d2;
                        st.insert({d+d2,{stop+1,i}});
                    }
                    }
                    
                }
            }
        }

        return -1;
        
    }
};