class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minel = INT_MAX;
        for(int i:nums) minel = min(minel,i);
        int ans = 0;
        for(int i:nums){
            ans+=i-minel;
        }
        return ans;
    }
};