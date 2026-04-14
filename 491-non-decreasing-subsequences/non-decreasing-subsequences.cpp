class Solution {
public:
        set<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& elem, int prev, int ind) {
        if (ind == nums.size()) {
            if (elem.size() >= 2) {
                ans.insert(elem);
            }
            return;
        }
        if (nums[ind] >= prev) {
            elem.push_back(nums[ind]);
            solve(nums, elem, nums[ind], ind + 1);
            elem.pop_back(); // Backtrack
        }
        solve(nums, elem, prev, ind + 1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int prev = nums[0];
        vector<int>  elem;
        solve(nums,elem,-101,0);
        vector<vector<int>> ans2;
        for(vector<int> v:ans){
            ans2.push_back(v);
        }
        return ans2;
    }
};