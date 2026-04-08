class Solution {
public:
int M = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(vector<int> q:queries){
            int idx = q[0];
            while(idx<=q[1]){
                nums[idx] = (int)(((long long)nums[idx]*q[3]) % M);
                idx+=q[2];
            }  
        }

        int ans= nums[0];
        for(int i = 1;i<nums.size();i++){
            ans = ans^nums[i];
        }
        return ans;

    }
};