class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;
        int mini = INT_MAX,maxi = INT_MIN;
        for(int i :nums){
            mini = min(mini,i),maxi = max(maxi,i);
        }
        if(mini+k > maxi-k) return 0;
        return (maxi-mini-2*k);
    }
};