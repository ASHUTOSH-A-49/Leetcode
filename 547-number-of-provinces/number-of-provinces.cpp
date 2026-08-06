class DSU{
    vector<int> rank,size,par;
public:
    DSU(int n){
        rank.assign(n+1,0);
        size.assign(n+1,0);
        par.assign(n+1,0);
        for(int i = 1;i<=n;i++) par[i] = i; //1 based
        

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
    void unionBySize(int u,int v){
        int ult_pu = findUpar(u);
        int ult_pv = findUpar(v);
        if(ult_pu==ult_pv) return;
        if(size[ult_pu] < size[ult_pv]){
            par[ult_pu] = ult_pv; 
        }else if(size[ult_pu] > size[ult_pv]){
            par[ult_pv] = ult_pu;
        }else{
            par[ult_pv] = ult_pu;
            //if equal attach v to u and as they were equal new rank increments by  aafter attaching (DRY RUN TO UNDERSTAND)
            size[ult_pu]+=size[ult_pv];
        }
    }

    bool checkComp(int u,int v){
        return (findUpar(u)==findUpar(v));
    }
        
};
class Solution {
public:
//DSU APPROACH

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU ds(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==j) continue;
                if(isConnected[i][j]){
                    if(ds.checkComp(i+1,j+1)) continue;
                    ds.unionBySize(i+1,j+1);
                }
            }
        }
        int comp = 0;
        for(int i = 1;i<=n;i++){
            if(ds.findUpar(i)==i) comp++;
        }
        return comp;
    }
};