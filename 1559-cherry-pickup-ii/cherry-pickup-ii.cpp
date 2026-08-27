class Solution {
public:
int dp[72][72][72];
int solve(int i,int j1,int j2,int n,int m,vector<vector<int>>& g){
    if(j1<0 || j1>=m || j2<0 || j2>=m) return 0;
    if(i==n-1) {
        if(j1==j2) return g[i][j1];
        else return g[i][j1] + g[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    //explore all paths 
    // for each alice bob has 3 moves , therefore total 9 combos
    int ans= 0;
    for(int dj1 = -1;dj1<2;dj1++){
        for(int dj2 = -1;dj2<2;dj2++){
            int c1 = j1+dj1,c2 = j2+dj2;
            if(c1<0 || c1>=m || c2<0 || c2>=m) continue;
            if(j1==j2) ans = max(ans, g[i][j1]+solve(i+1,c1,c2,n,m,g));
            else ans = max(ans,g[i][j1]+g[i][j2] + solve(i+1,c1,c2,n,m,g));
        }
    }
    return dp[i][j1][j2] = ans;
    
   
}
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size(),m = grid[0].size();
        return solve(0,0,m-1,n,m,grid);
    }
};