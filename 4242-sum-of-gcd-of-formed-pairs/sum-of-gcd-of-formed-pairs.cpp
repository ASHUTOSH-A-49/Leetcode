class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMax(n);
        preMax[0] = nums[0];
        for(int i = 1;i<n;i++) preMax[i] = max(nums[i],preMax[i-1]);
        vector<int> preGcd(n);
        preGcd[0] = nums[0];
        for(int i = 1;i<n;i++) preGcd[i] = gcd(nums[i],preMax[i]);
        sort(preGcd.begin(),preGcd.end());
        long long sum = 0;
        for(int i = 0;i<n/2;i++){
            sum+=gcd(preGcd[i],preGcd[n-i-1]);
        }
        return sum;
    }
};