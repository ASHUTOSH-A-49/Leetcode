class Solution {
public:
    int arob(int i,vector<int>& nums,vector<int> & memo){
        if(i<0) return 0;
        if(memo[i]!=-1){
            return memo[i];
        }
        int pick = nums[i] + arob(i - 2, nums, memo);
        int skip = 0 + arob(i - 1, nums, memo);
        return memo[i] = max(pick, skip);
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n+1,-1);
        return arob(n-1,nums,memo);
    }
};