class Solution {
public:
int BSFind(vector<int> & nums,int target){
    int l = 0,h = nums.size()-1,ans = -1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>target) h = mid-1;
        else l = mid+1;
    }
    return ans;
}
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int m = 1;m<=100;m++){
            if(BSFind(nums,m*k)==-1) return m*k;
        }
        return k*101;
    }
};