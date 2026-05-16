class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size()-1,ans = 5001;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                //shrink the search space 
                ans = min(ans,nums[mid]);
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid]){
                ans = min(nums[low],ans);
                low = mid+1;
            }
            else{
                ans = min(nums[mid],ans);
                high = mid-1;
            }
        }
        return ans;
    }
};