class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        if(k==1){
            map<int,int> mp;
            for(int i:nums) mp[i]++;
            for(auto [i,f]:mp) {
                if(f==1){
                    if(i>ans) ans = i;
                }
            }
        }else if(k==n){
            for(int i:nums) ans = max(ans,i);
        }else{
            map<int,int> mp;
            for(int i:nums) mp[i]++;
            if(mp[nums[0]]>1 && mp[nums[n-1]]>1) ans = -1;
            else{
                if(mp[nums[0]]==1 && mp[nums[n-1]]==1) ans = max(nums[0],nums[n-1]);
                else if(mp[nums[0]]==1) ans = nums[0];
                else ans = nums[n-1];
            }

        }
        return ans;
    }
};