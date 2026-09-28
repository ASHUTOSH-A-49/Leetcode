class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //approach  - using ordered map
        int n=nums.size();
        vector<int>ans;
        map<int,int>mp;
        int l=0;
        int r=k-1;
        for(int i=l;i<=r;i++){
            mp[nums[i]]++;
        }
        while(r<n){
            ans.push_back((*mp.rbegin()).first);
            mp[nums[l]]--;
            if(!mp[nums[l]]) mp.erase(nums[l]);
            l++;
            r++;
            if(r==n)continue;
            mp[nums[r]]++;
        }
        return ans;
        
    }
};