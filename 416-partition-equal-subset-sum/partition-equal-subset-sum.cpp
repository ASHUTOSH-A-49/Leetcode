int dp[201][200001];
class Solution {
public:

    int solve(int idx, vector<int> & arr,int &n, int sum,int &tot){
        if(sum> tot/2) return false;
        if(sum*2==tot) return true;
        if(idx==n-1) {
            if((sum+arr[idx])*2 == tot) return true;
            return false;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool take = solve(idx+1,arr,n,sum+arr[idx],tot);
        bool skip = solve(idx+1,arr,n,sum,tot);
        return dp[idx][sum] = take || skip;
        
    }
    bool canPartition(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int tot = 0;
        for(int i:nums) tot+=i;
        return solve(0,nums,n,0,tot);
    }
};