class Solution {
public:
    //tabulation approach (space optimised)
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        if(n==1) return nums[0];
        int t2 = nums[0];
        int t1= max(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            int curr = max(t1,t2+nums[i]);
            // if robbed i-1 th value then dont rob curr house else rob current house
            t2 = t1;
            t1 = curr;
        }
        return t1;
    }
};