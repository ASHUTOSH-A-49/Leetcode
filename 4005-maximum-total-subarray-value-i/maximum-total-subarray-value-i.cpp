class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = 1e9,maxi = 0;
        for(int i:nums){
            maxi = max(maxi,i);
            mini = min(mini,i);
        }
        return (long long)k*(maxi-mini);
    }
};