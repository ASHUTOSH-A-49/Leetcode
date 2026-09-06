class Solution {
public:
//TABULATION (BOTTOM UP) with SPACE OPTIMIZ'N
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(2001, 0);
        
        dp[0+1000] = 1; //sum  = 0 base case
        
        for (int i = n - 1; i >= 0; i--) {
            vector<int> next_dp(2001, 0);
            for (int s = 1000; s >= -1000; s--) {
                int sub = 0, add = 0;
                if (s - nums[i] >= -1000) sub = dp[s - nums[i] + 1000];
                if (s + nums[i] <= 1000)  add = dp[s + nums[i] + 1000];
                next_dp[s + 1000] = sub + add;
            }
            dp = move(next_dp);
        }
        return dp[target+1000];


    }
};