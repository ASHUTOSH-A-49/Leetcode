class Solution {
public:
//tabulation (BOTTOM-UP) approach with space optimis.n
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        dp[n-1] = 1;
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                int r = 0,d = 0;
                if(j!=n-1) r = dp[j+1]; //holds fresh updated curr vec right
                d = dp[j]; //holds stale down vec values
                dp[j] = r+d;
            }
        }
        return dp[0];
        
    }
};