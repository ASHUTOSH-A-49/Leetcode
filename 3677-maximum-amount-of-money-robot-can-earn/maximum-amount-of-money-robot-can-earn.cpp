class Solution {
public:
    int solve(vector<vector<vector<int>>> & memo,vector<vector<int>>& coins,int i,int j,int m,int n,int k){
        if(i>=m || j>=n){
            return INT_MIN;
        }
        int c = coins[i][j];
        if(i==m-1 && j==n-1){
            if(k>0) return max(0,c);
            return c;
        }
        int res = memo[i][j][k];
        if(res!=INT_MIN){
            return res;
        }
        res = max(solve(memo,coins,i+1,j,m,n,k),solve(memo,coins,i,j+1,m,n,k))+c;
        if(k>0 && c<0){
            res = max({res,solve(memo,coins,i+1,j,m,n,k-1),solve(memo,coins,i,j+1,m,n,k-1)});
        }
        return memo[i][j][k] = res;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return solve(memo,coins,0,0,m,n,2);
    }
};