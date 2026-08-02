class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        double compar = (double)a/b;
        int sub = 0;
        for(int i = 0;i<n;i++){
            double x = 0,y = 0;
            if(nums[i]&1) y++;
            else x++;
            if(y>0){
                if(x/y <= compar)sub++;
            }
            for(int j = i+1;j<n;j++){
                if(nums[j]&1) y++;
                else x++;
                if(y>0){
                if(x/y <= compar)sub++;
                }
                
            }
        }
        return sub;
        
    }
};