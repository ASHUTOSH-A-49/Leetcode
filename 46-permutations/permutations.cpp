class Solution {
public:
vector<vector<int>> ans;
void solve(set<int>&st,vector<int> & temp,vector<int> & nums){
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
    }
    for(int i = 0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                solve(st,temp,nums);
                // cout<<temp.size()<<endl;
                temp.pop_back();
                st.erase(nums[i]);
            }
    }



}
    vector<vector<int>> permute(vector<int>& nums) {
        set<int> st;
        vector<int> temp;
        solve(st,temp,nums);
        return ans;
    }
};