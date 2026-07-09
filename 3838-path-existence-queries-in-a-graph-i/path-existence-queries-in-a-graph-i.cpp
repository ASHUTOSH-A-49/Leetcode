class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n,0);
        int cmp = 0;
        for(int i = 1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff)cmp++;
            comp[i] = cmp;
        }
        vector<bool> ans;
        for(vector<int> q:queries){
            if(comp[q[0]]==comp[q[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
        
    }
};