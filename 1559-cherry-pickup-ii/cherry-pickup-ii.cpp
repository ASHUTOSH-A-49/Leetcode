class Solution {
public:
// Tabulation -BOTTOM UP 
    int cherryPickup(vector<vector<int>>& g) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = g.size(),m = g[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m)));
        int ans = 0;
        for(int i = n-1;i>=0;i--){
            
            for(int j1 = 0;j1<m;j1++){
                for(int j2 = 0;j2<m;j2++){
                    if(i==n-1){
                        if(j1==j2) dp[i][j1][j2] = g[i][j1];
                        else dp[i][j1][j2] = g[i][j1]+g[i][j2];
                    }else{
                        int rmax = 0;
                        for(int dj1 = -1;dj1<2;dj1++){
                            for(int dj2 = -1;dj2<2;dj2++){
                                int c1 = j1+dj1,c2 = j2+dj2;
                                if(c1<0 || c1>=m || c2<0 || c2>=m) continue;
                                if(j1==j2) rmax = max(rmax, g[i][j1]+dp[i+1][c1][c2]);
                                else rmax = max(rmax,g[i][j1]+g[i][j2] + dp[i+1][c1][c2]);
                            }
                        }
                        dp[i][j1][j2] = rmax;
                    }
                }
            }
        }
        return dp[0][0][m-1];
    }
};