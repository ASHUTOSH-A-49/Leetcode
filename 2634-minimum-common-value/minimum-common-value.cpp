class Solution {
public:
    bool BSelem(int target,vector<int> & nums){
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = high - (high-low)/2;
            if(nums[mid]==target) return true;
            if(target<nums[mid]) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i : nums1){
            bool check  = BSelem(i,nums2);
            if(check) return i;
        }
        return -1;
    }
};