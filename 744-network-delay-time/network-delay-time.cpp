class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> G(n+1);
        for(auto t:times){
            int u = t[0],v = t[1],p = t[2];
            G[u].push_back({p,v});
        }
        set<pair<int,int>> st; //dist, node
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        st.insert({0,k});
        
        while(!st.empty()){
            auto [d,node] = *st.begin();
            st.erase(st.begin());
            if (d>dist[node]) continue;
            for(auto [d2,i]:G[node]){
                // if(dist[i]!=1e9){
                //     st.erase({dist[i],i});
                // }
                if(d+d2<dist[i]){
                    dist[i] = d+d2;
                    st.insert({dist[i],i});
                }
            }
        }
        int maxd = 0;
        for(int i = 1;i<=n;i++){
            cout<<dist[i]<<" ";
            maxd = max(maxd,dist[i]);
        }
        return (maxd==1e9) ? -1 : maxd;
    }
};