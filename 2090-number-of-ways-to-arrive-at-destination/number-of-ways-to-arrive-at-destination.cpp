class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int V = n;
        int MOD = 1e9+7;
        vector<vector<pair<int,int>>>G(V);
        for(auto e:roads){
            int u = e[0],v = e[1],w = e[2];
            G[u].push_back({v,w});
            G[v].push_back({u,w});
        }
        long long cntways = 1;
        vector<long long> dist(V,1e18);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        set<pair<long long,int>> st;
        st.insert({0,0});//dist,node
        while(!st.empty()){
            auto[d,root] = *st.begin();
            st.erase(st.begin());
            if(d>dist[root])continue;
            for(auto [node,d2]:G[root]){
                if(d+d2<dist[node]){
                    dist[node]=d+d2;
                    ways[node]=ways[root];
                    st.insert({dist[node],node});
                }else if(d+d2==dist[node]){
                    ways[node]=(ways[node]+ways[root])%MOD;
                }
            }
        }
        return ways[n-1];

    }
};