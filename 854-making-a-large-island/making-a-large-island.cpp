class DSU{   
public:
    vector<int> rank,size,par;
    DSU(int n){
        rank.assign(n+1,0);
        size.assign(n,1); 
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
    void unionBySize(int u,int v){
        int ult_pu = findUpar(u);
        int ult_pv = findUpar(v);
        if(ult_pu==ult_pv) return;
        if(size[ult_pu] < size[ult_pv]){
            par[ult_pu] = ult_pv; 
            size[ult_pv] += size[ult_pu];
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int siz = n*n;
        vector<int> vis(siz,0);
        DSU ds(siz);
        int maxsiz = 0;
        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++){
                if (grid[r][c] == 0) continue;
                int nodeid = r*n+c;
                vis[nodeid] = 1;
                int drow[] = {-1,1,0,0};
                int dcol[] = {0,0,-1,1};
                for(int i = 0;i<4;i++){
                int nrow = r+drow[i], ncol = c+dcol[i];
                if(nrow<0 || ncol<0 || nrow>=n || ncol>=n) {
                    //out of bounds;
                    continue;
                }
                int nodeid2  = nrow*n+ncol;
                if(ds.checkComp(nodeid,nodeid2)) {
                    //if already under same component , skip
                    continue;
                }
                if(vis[nodeid2]){
                    //if nodeid2 is already an island
                   ds.unionBySize(nodeid,nodeid2);
                }
                
            }
            }
        }

        for(int i = 0;i<siz;i++){
            maxsiz = max(maxsiz,ds.size[ds.findUpar(i)]);
        }
        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++){
                if(grid[r][c]==0){
                    int cntsiz = 1; //initially size  = 1 as taking this node only
                    int nodeid = r*n+c;
                    int drow[] = {-1,1,0,0};
                    int dcol[] = {0,0,-1,1};
                    //check left right and add size if there are islands
                    unordered_set<int> uniq; //avoid adding same island twice
                    for(int i = 0;i<4;i++){
                        int nrow = r+drow[i], ncol = c+dcol[i];
                        if(nrow<0 || ncol<0 || nrow>=n || ncol>=n) {
                            //out of bounds;
                            continue;
                        }
                        int nodeid2  = nrow*n+ncol;
                        if(vis[nodeid2]){
                            uniq.insert(ds.findUpar(nodeid2));
                            //if nodeid2 is already an island
                        }
                    }
                    for(auto parentId : uniq) {
                        cntsiz += ds.size[parentId];
                    }
                    maxsiz = max(maxsiz,cntsiz);

                }

            }
        }
        return maxsiz;
        
    }
};