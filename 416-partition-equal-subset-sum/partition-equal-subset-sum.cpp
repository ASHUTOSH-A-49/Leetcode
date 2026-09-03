
class Solution {
public:
//TABULATION WITH SPACE OPT
    bool canPartition(vector<int>& nums) {
        int tot = 0;
        for(int i:nums) tot+=i;
        if(tot&1) return false;
        int sum = tot/2;

        int n = nums.size();
        vector<bool> dp(sum + 1, false);

        dp[0] = true;

        if (nums[n-1] <= sum) {
            dp[nums[n-1]] = true;
        }

        for (int idx = n - 2; idx >= 0; idx--) {
            for (int t = sum; t >= 1; t--) {
                bool skip = dp[t];
                bool take = false;

                if (nums[idx] <= t) {
                    take = dp[t - nums[idx]];
                }

                dp[t] = take || skip;
            }
        }

        return dp[sum];
    }
};