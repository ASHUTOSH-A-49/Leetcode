class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        if(n&1){
            int med = nums[n/2];
            for(int i:nums){
                ans+=abs(i-med);
            }
        }else{
            int med1 = nums[n/2];
            int med2 = nums[n/2-1];
            int ans1 = 0,ans2 = 0;
            for(int i:nums){
                ans1+=abs(i-med1);
                ans2+=abs(i-med2);
            }
            ans = min(ans1,ans2);
        }
        return ans;
    }
};