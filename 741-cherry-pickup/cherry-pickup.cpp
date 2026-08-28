class Solution {
public:
int dp[51][51][51][51];
int solve(vector<vector<int>> &g,int r1,int c1,int r2,int c2,int n){
    //IMPORTANT CONVERSION - keep two robots start from r1 ,c1 , r2 c2 and then go to n-1,n-1 is equivalent to going once and coming back to 0,0 
    if(r1<0 || r2<0 || r1>=n || r2>=n ||  c1<0 || c2<0 || c1>=n || c2>=n){
        return -1e8;
    }
    if(g[r1][c1]==-1 || g[r2][c2]==-1) return -1e8;
    if(r1==n-1 && c1==n-1) return g[r1][c1];
    if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
    int cherries = 0;
    if(r1==r2 && c1==c2){
        cherries+=g[r1][c1];
    }else
    cherries+=g[r1][c1] + g[r2][c2];

    int f1 = solve(g,r1+1,c1,r2+1,c2,n);//both vertical
    int f2 = solve(g,r1+1,c1,r2,c2+1,n); // first vertical second horiz
    int f3 = solve(g,r1,c1+1,r2+1,c2,n); //first horiz second vert
    int f4 = solve(g,r1,c1+1,r2,c2+1,n); //both horiz

    return dp[r1][c1][r2][c2] = cherries+max({f1,f2,f3,f4});
}
    int cherryPickup(vector<vector<int>>& g) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        memset(dp,-1,sizeof(dp));
        int n = g.size(); 
        int ans = solve(g,0,0,0,0,n); //start both robo from 0,0
        return max(0,ans);
        
    }
};