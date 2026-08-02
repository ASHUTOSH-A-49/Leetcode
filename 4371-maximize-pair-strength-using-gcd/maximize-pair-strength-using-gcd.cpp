class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0;i<n;i++){
            for(int j= i+1;j<n;j++){
                long long mul = (long long)nums[i]*nums[j];
                long long gc = gcd(nums[i],nums[j]);
                long long div = gc*gc;
                ans = max(mul/div,ans);
            }
        }
        return ans;
    }
};