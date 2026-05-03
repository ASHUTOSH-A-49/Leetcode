class Solution {
public:
int memo [201][1001]; //initialize memo on index and target
    int solve(vector<int> &nums, int target, int idx) {
    if (target==0) {
        return 1;
    }
    if (target<0 || idx >= nums.size()) {
        return 0;
    }
    if(memo[idx][target]!=-1){
        return memo[idx][target];
    }

    int take = solve(nums, target-nums[idx], 0);
    int not_take = solve(nums, target, idx + 1);
    return memo[idx][target] = take+not_take;

}
    int combinationSum4(vector<int>& nums, int target) {
        memset(memo,-1,sizeof(memo)); //initialize with -1 all values
        return solve(nums,target,0);;
    }
};