class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int k = distanceThreshold;
        vector<vector<pair<int,int>>> G(n);
        for(auto e:edges){
            int u = e[0],v = e[1],w = e[2];
            G[u].push_back({v,w});
            G[v].push_back({u,w});
        }
        set<pair<int,int>> val; //city,node
        for(int i = 0;i<n;i++){
            vector<int> dist(n,1e9);
            set<pair<int,int>> st; //{dist,node}
            dist[i] = 0;
            st.insert({0,i});
            while(!st.empty()){
                auto [d,u] = *st.begin();
                st.erase(st.begin());
                for(auto [v,d2]:G[u]){
                    if(d+d2<dist[v]){
                        if(dist[v]!=1e9) st.erase({dist[v],v});
                        dist[v] = d+d2;
                        st.insert({dist[v],v});
                    }
                }
            }
            int city = 0;
            for(int c = 0;c<n;c++){
                if(c==i) continue;
                if(dist[c]<=k) city++;
            }
            val.insert({city,i});
        }
        int city = val.begin()->first,node = -1;
        for(auto [c,n]:val){
            if(c==city){
                node = n;
            }else{
                break;
            }
        }
        return node;
    }
};