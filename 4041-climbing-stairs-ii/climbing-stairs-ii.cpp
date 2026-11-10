class Solution {
public:
vector<int> dp;
int INF = 1e9;
    int climbStairs(int n, vector<int>& costs) {
        dp.assign(n+1,-1);
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            int j1 = INF,j2 = INF,j3 = INF;
            if(i+1<=n) j1 = dp[i+1] + 1 + costs[i];
            if(i+2<=n) j2 = dp[i+2] + 4 + costs[i+1];
            if(i+3<=n) j3 = dp[i+3]  + 9 + costs[i+2];
            dp[i] = min({j1,j2,j3});
        }
        return dp[0];


    }
};