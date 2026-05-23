class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0,high = nums.size()-1,found = 0,ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                ans =mid;
                break;
            }
            else if(nums[low]>nums[mid]){
                if(target>nums[mid] && target<=nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }else{
                if(target<nums[mid] && target>=nums[low]) high = mid-1;
                else low = mid+1;
            }
        }
        return ans;
        
    }
};