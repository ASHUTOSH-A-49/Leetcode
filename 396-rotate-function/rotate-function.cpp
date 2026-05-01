class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int first = 0,sum = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            first+=i*nums[i];
        }
        maxi = max(maxi,first);
        for(int i = 1;i<n;i++){
            first = first+sum-n*nums[n-i];
            maxi = max(maxi,first);
        }
        return maxi;
    }
};