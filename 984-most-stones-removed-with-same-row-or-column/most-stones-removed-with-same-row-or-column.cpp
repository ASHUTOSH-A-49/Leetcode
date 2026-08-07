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
            size[ult_pv]+=size[ult_pu]; 
        }else{
            par[ult_pv] = ult_pu;
            size[ult_pu]+=size[ult_pv];
        }
    }

    bool checkComp(int u,int v){
        return (findUpar(u)==findUpar(v));
    }
        
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        //coordinate mapping take all rows as nodes and cols start from maxrow+1, i.e. col0 = maxrow+1, col1 = maxrow+2 and so on...
        int xmax = 0,ymax = 0;
        for(auto c:stones){
            xmax= max(xmax,c[0]);
            ymax= max(ymax,c[1]);
        }
        int siz = xmax+ymax+1;
        DSU ds(siz+1);
        vector<int> vis(siz+1);
        for(auto c:stones){
            int rnode = c[0];
            int colnode = c[1]+xmax+1;
            vis[rnode] = 1;
            vis[colnode] = 1;
            if(ds.checkComp(rnode,colnode)) continue;
            ds.unionBySize(rnode,colnode);
        }
        int components = 0;
        for (int i = 0; i < siz; i++) {
            if(vis[i]){
                if (ds.findUpar(i) == i) {
                components++;
                }
            }
            
        }
        return stones.size()-components;

    }
};