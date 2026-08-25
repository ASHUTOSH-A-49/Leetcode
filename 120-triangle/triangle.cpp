class Solution {
public:
// int dp[202][202];
//     int solve(int i,int j,vector<vector<int>>& triangle,int n){
//         if(i==n-1) return triangle[i][j];
//         if(dp[i][j]!=INT_MAX) return dp[i][j];
//         int take1 = solve(i+1,j,triangle,n);
//         int take2 = solve(i+1,j+1,triangle,n);
//         return dp[i][j] = triangle[i][j]+min(take1,take2);
//     }
    int minimumTotal(vector<vector<int>>& triangle) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = triangle.size();
        vector<int> dp(n);
        for(int i = 0;i<n;i++){
            dp[i] = triangle[n-1][i];
        }
        int siz = n-2;
        for(int i = n-2;i>=0;i--){
            vector<int> temp(dp.begin(),dp.begin()+siz+2);
            for(int j = siz;j>=0;j--){
                dp[j] = triangle[i][j]+min(temp[j],temp[j+1]);
            }
            siz--;
        }
        return dp[0];
    }
};