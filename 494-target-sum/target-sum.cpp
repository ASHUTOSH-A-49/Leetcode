class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2001, 0));
        
        dp[n][1000] = 1;
        
        for(int i = n-1;i>=0;i--){
            for(int s = 1000;s>=-1000;s--){
                int sub = 0,add = 0;
                if(s-nums[i]>=-1000)sub = dp[i+1][s-nums[i]+1000];
                if(s+nums[i] <=1000) add = dp[i+1][s+nums[i]+1000];
                dp[i][s+1000] = sub+add;
            }
        }
        return dp[0][target+1000];


    }
};