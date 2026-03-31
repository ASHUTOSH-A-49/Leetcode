class Solution {
public:
    void solve(vector<vector<int>> & res,vector<int>& candidates, int target,int i,vector<int> & ls){
        if(i==candidates.size()){
            if(target==0){
                res.push_back(ls);
            }
            return;
        }
        if(candidates[i]<=target){
            ls.push_back(candidates[i]);
            solve(res,candidates,target-candidates[i],i,ls);
            ls.erase(ls.begin()+ls.size()-1);
        }
        solve(res,candidates,target,i+1,ls);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> ls;
    solve(res,candidates,target,0,ls);
    return res;
    }
};