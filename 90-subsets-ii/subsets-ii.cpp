class Solution {
public:
set<vector<int>> ans;
    void solve(vector<int>& nums,int i,vector<int> & el){
        //base
        if(i>=nums.size()){
            vector<int> b = el;
            sort(b.begin(),b.end());
            ans.insert(b);
            return;
        }
        //take
        el.push_back(nums[i]);
        solve(nums,i+1,el);
        el.pop_back(); //backtrack;
        //not take
        solve(nums,i+1,el);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> el;
        solve(nums,0,el);
        vector<vector<int>> ans1;
        for(vector<int> v:ans){
            ans1.push_back(v);
        }
        return ans1;
    }
};