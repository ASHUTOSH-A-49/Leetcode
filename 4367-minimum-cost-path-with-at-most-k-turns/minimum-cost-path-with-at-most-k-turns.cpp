class Solution {
public:
    int dp[76][76][76][5];
    int solve(int i,int j,int &m,int &n,vector<vector<int>> & g,int &k,int turns,int prev){
        if(turns>k) return INT_MAX;
        if(i<0 || j<0 || i>=m || j>=n) return INT_MAX;
        if(i== m-1 && j==n-1){
            return g[i][j];
        }
        if(dp[i][j][turns][prev]!=-1) return dp[i][j][turns][prev];
        int l,r,u,d;
        l = solve(i,j-1,m,n,g,k,(prev==0 || prev==1)?turns:turns+1,1);
        r = solve(i,j+1,m,n,g,k,(prev==0 || prev==2)?turns:turns+1,2);
        u = solve(i-1,j,m,n,g,k,(prev==0 || prev==3)?turns:turns+1,3);
        d = solve(i+1,j,m,n,g,k,(prev==0 || prev==4)?turns:turns+1,4);
        int res = min({l,r,u,d});
        return (res==INT_MAX) ? dp[i][j][turns][prev] = INT_MAX : dp[i][j][turns][prev] = g[i][j]+res;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        //l = 1,r = 2,u = 3,d = 4;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(k>75) k = 75;
        memset(dp,-1,sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        int res = solve(0,0,m,n,grid,k,0,0);
        return (res==INT_MAX) ? -1 :res;
    }
};