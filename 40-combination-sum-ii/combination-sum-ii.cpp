class Solution {
public:
void solve(vector<vector<int>> & res,vector<int>& candidates, int target,int ind,vector<int> & ls){
        
            if(target==0){
                // vector<int> b = ls;
                // sort(b.begin(),b.end());
                res.push_back(ls);
                return;
            }
            
        
        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            ls.push_back(candidates[i]);
            solve(res, candidates, target - candidates[i], i + 1, ls);
            ls.pop_back(); // Backtrack
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ls;
        solve(res, candidates, target, 0, ls);
        return res;
    }
};