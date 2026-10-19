class Solution {
public:
//approach 2- number < target (start point) and then number = target
//O(n) approach
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cntnum = 0,cntless = -1;
        for(int i :nums){
            if(i<target) cntless++;
            if(i==target) cntnum++;
        }
        vector<int> ans;
        for(int i = cntless+1;i<=cntless+cntnum;i++) ans.push_back(i);
        return ans;

    }
};