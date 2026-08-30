class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int cnt;
        unordered_map<int,int> mp;
        int prev = nums[0];
        mp[prev] = 1;
        cnt = 1;
        for(int i = 0;i<n;i++)
        {
            if(nums[i]==prev) continue;
            else{
                if(mp[prev]==1)mp[prev] = 2;
              if(mp[nums[i]]==0) {
                  mp[nums[i]] = 1;
                  cnt++;
              }  else if(mp[nums[i]]==2){
                  cnt--;
                  mp[nums[i]]=3;
              }
            }
            prev = nums[i];
        }   
        
        return cnt;
    }
};