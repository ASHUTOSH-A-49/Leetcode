class Solution {
public:
    int solve(vector<vector<int>> &memo, int target, vector<int> &nums, int i, int sum) {
        if (i == nums.size()) {
            return (sum == target) ? 1 : 0;
        }
        if (memo[i][sum + 1000] != -1) {
            return memo[i][sum + 1000];
        }
        int take = solve(memo, target, nums, i + 1, sum + nums[i]);
        int nott = solve(memo, target, nums, i + 1, sum - nums[i]);
        return memo[i][sum + 1000] = take + nott;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(2001, -1));
        return solve(memo, target, nums, 0, 0);
    }
};