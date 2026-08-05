class DSU{
    vector<int> rank,par;
public:
    DSU(int n){
        rank.assign(n+1,0);
        par.assign(n+1,0);
        for(int i = 0;i<n;i++) par[i] = i; //0 based
        

    }

    int findUpar(int u){
        if(par[u]==u) return u;
        return par[u] = findUpar(par[u]); // PATH COMPRESSION
    }

    void unionByRank(int u,int v){
        int ult_pu = findUpar(u);
        int ult_pv = findUpar(v);
        if(ult_pu==ult_pv) return;
        if(rank[ult_pu] < rank[ult_pv]){
            par[ult_pu] = ult_pv; 
        }else if(rank[ult_pu] > rank[ult_pv]){
            par[ult_pv] = ult_pu;
        }else{
            par[ult_pv] = ult_pu;
            //if equal attach v to u and as they were equal new rank increments by  aafter attaching (DRY RUN TO UNDERSTAND)
            rank[ult_pu]++;
        }
    }

    bool checkComp(int u,int v){
        return (findUpar(u)==findUpar(v));
    }
        
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(connections.size()<n-1) return -1;
        DSU ds(n);
        for(auto v:connections){
            ds.unionByRank(v[0],v[1]);
        }
        //counter approach (optimised space)
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUpar(i) == i) {
                components++;
            }
        }
        return components - 1;
    }
};