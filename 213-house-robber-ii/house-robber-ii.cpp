class Solution {
public:
    int arob(int i,int start, vector<int>& nums, vector<int>& memo) {
        if (i < start) return 0;
        if (memo[i] != -1) {
            return memo[i];
        }
        int pick = nums[i] + arob(i - 2,start, nums, memo);
        int skip = 0 + arob(i - 1,start, nums, memo);
        return memo[i] = max(pick, skip);
    }
    int rob(vector<int>& nums) {
        // Since House[1] and House[n] are adjacent, they cannot be robbed
        // together. Therefore, the problem becomes to rob either
        // House[1]-House[n-1] or House[2]-House[n], depending on which choice
        // offers more money. Now the problem has degenerated to the House
        // Robber, which is already been solved.
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> memo1(n, -1);
        int planA = arob(n - 2, 0, nums, memo1);
        vector<int> memo2(n, -1);
        int planB = arob(n - 1, 1, nums, memo2);

        return max(planA, planB);
    }
};