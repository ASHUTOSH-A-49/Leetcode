class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,vector<int> & nums,int next){
        if (i < 0) return 0;
        int nextel = -1;
        if (next == -1) {
            nextel = 0;
        } else {
            int diff = next - nums[i];
            if (diff > 2) return 0;
            if (diff >= 0 && diff <= 2) {
                nextel = diff + 1;
            }
        }
        if (nextel != -1 && dp[i][nextel] != -1) {
            return dp[i][nextel];
        }
        int ans1 = 0,ans2 = 0,skip = 0;
        if(next==-1){
            ans1 = 1+solve(i-1,nums,nums[i]+1);
            ans2 = 1+solve(i-1,nums,nums[i]);
            skip = solve(i - 1, nums, -1);
        }else{
            if (next - nums[i] == 1) ans2 = 1 + solve(i - 1, nums, nums[i]);
            if (next - nums[i] == 2) ans1 = 1 + solve(i - 1, nums, nums[i] + 1);
            skip = solve(i - 1, nums, next);
        }
        int res = max(ans1, max(ans2, skip));
        if (nextel != -1) {
            dp[i][nextel] = res;
        }
        return res;

    }
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,vector<int>(4,-1));
        if(n==1) return 1;
        sort(nums.begin(),nums.end());
        return solve(n-1,nums,-1);
    }
};