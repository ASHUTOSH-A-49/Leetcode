class Solution {
public:
//recursive solution
vector<vector<int>> ans;
    void solve(vector<int>& nums,int i,vector<int> & el){
        //base
        if(i>=nums.size()){
            ans.push_back(el);
            return;
        }
        //take
        el.push_back(nums[i]);
        solve(nums,i+1,el);
        el.pop_back(); //backtrack;
        //not take
        solve(nums,i+1,el);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> el;
        solve(nums,0,el);
        return ans;
    }
};