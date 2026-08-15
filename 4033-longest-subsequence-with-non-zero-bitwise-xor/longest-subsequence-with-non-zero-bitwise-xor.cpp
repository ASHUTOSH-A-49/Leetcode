class Solution {
public:
int dp[100001];
int solve(int idx,int xorval,vector<int> & nums){
    int n = nums.size();
    if(idx==n) return 0;
    if(idx==n-1){
        xorval = xorval^nums[n-1];
        if(xorval!=0) return 1;
        return 0;
    }
    if(dp[idx]!=-1) return dp[idx];
    int take = 0,skip = 0;
    take =1+ solve(idx+1,xorval^nums[idx],nums);
    skip =solve(idx+1,xorval,nums);
    return dp[idx] = max(take,skip);
}
    int longestSubsequence(vector<int>& nums) {
        //edge case all 0 in the array
        int checknat = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]>0) {
                checknat = 1;
                break;
            }
        }
        if(!checknat) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums);
    }
};