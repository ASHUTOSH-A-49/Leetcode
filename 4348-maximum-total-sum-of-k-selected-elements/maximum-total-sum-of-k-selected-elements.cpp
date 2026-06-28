class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long sum = 0;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i = 0;i<k;i++){
            long long m = (long long)mul* nums[i];
            (m>nums[i]) ? sum+=m : sum+=nums[i];
            mul--;
        }
        return sum;
    }
};