class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> premax(n),postmin(n);
        int mini = INT_MAX,maxi = -1;
        for(int i = 0;i<n;i++){
            maxi = max(maxi,nums[i]);
            premax[i] = maxi;
        }
        for(int i = n-1;i>=0;i--){
            mini = min(mini,nums[i]);
            postmin[i] = mini;
        }
        int idx = -1;
        for(int i = 0;i<n;i++){
            if(premax[i]-postmin[i]<=k) return i;
        }
        return idx;
    }
};