class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> G(n);
        for(auto e:edges){
            int u = e[0],v = e[1],w = e[2];
            G[u].push_back({v,w});//node,weight
        }
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        set<vector<int>> st;
        int start_char = labels[0] - 'a'; 
        st.insert({0, 0, start_char, 1}); // w,node,prevchar,cons
        dist[0][1]= 0;
        while(!st.empty()){
            auto v= *st.begin();
            st.erase(st.begin());
            int u= v[1],w = v[0],prev = v[2],cons = v[3];
            if (w > dist[u][cons]) continue;
            for(auto p:G[u]){
                int node = p.first,w1 = p.second;
                int nextch = labels[node] - 'a';
                int next_cons = (nextch == prev) ? cons + 1 : 1;
                if(next_cons > k) continue;

                if(w + w1 < dist[node][next_cons]){
                    dist[node][next_cons] = w + w1;
                    st.insert({w + w1, node, nextch, next_cons});
                }
            }

        }
        int ans = INT_MAX;
        for(int c = 1; c <= k; ++c) {
            ans = min(ans, dist[n-1][c]);
        }
        return (ans==INT_MAX)?-1:ans;
        
    }
};