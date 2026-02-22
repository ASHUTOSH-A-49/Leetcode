class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int p1 = 0,p2 = 0,toggle=0;//0 for p1 and 1 for p2
        for(int i = 0;i<nums.size();i++){
            if(i%6==5){
                toggle = !toggle;
            }
            if(nums[i]&1) toggle = !toggle;
            if(toggle) p2+=nums[i];
            else p1+=nums[i];

        }
        return p1-p2;
    }
};