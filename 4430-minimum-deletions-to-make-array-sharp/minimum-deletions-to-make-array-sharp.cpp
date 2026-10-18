class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int del = 0;
        int n = nums.size();
        for(int i = 0;i<n-1;){
            if(nums[i]==nums[i+1]){
                while(i<n-1 && nums[i]==nums[i+1]){
                del++;i++;
                }
                continue;
            }
            i++;
            
            
        }
        return del;
    }
};