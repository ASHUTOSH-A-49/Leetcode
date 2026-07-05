class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int cntmid = 0;
        int n = nums.size();
        int mid = nums[n/2];
        for(int i:nums){
            if(i==mid) cntmid++;
        }
        if(cntmid==1) return true;
        return false;
    }
};