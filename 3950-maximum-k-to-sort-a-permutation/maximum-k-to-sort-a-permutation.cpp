class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        bool first = false;
        for(int i = 0;i<n;i++){
            if(nums[i]==i) continue;
            if(ans == 0  && !first) {
                first = true;
                ans = nums[i];
            }
            else ans= ans & nums[i];
            cout<<ans<<endl;
        }
        return ans;
    }
};