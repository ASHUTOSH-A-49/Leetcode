class Solution {
public:
//approach 1 - sorting O(nlgn)
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target) ans.push_back(i);
        }
        return ans;
    }
};