class Solution {
public:
    bool check(vector<int>& nums) {
        int brkcnt = 0;
        int order = 1;
        int stind = -1;
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                brkcnt++;
                stind = i+1;
            }   
        }
        if(brkcnt>1){
            return false;
        }else if(stind==-1){
            return true;
        }
        else{
            
            for(int i = 0;i<n-1;i++){
                if(nums[(stind%n)]>nums[(stind+1)%n]){
                    order = 0;
                    break;
                }
                stind++;
            }
        }
        if(order){
            return true;
        }

        return false;
    }
};