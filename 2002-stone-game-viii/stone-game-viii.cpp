class Solution {
public:
// int dp[1000001];
// int solve(int i, vector<int> & pre,int n){
//     if(i==n-1) return pre[i];
//     if(dp[i]!=-1) return dp[i];
//     int take = pre[i]-solve(i+1,pre,n);
//     int skip = solve(i+1,pre,n);

//     return dp[i] = max(take,skip);
// }
    int stoneGameVIII(vector<int>& stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // memset(dp,-1,sizeof(dp));
        int n = stones.size();
        vector<int> nums;
        for(int i = 0;i<n;i++){
            if(stones[i]!=0) nums.push_back(stones[i]);
        }
        // for(int i:nums) cout<<i<<" ";
        // cout<<endl;
        int n1 = nums.size();
        vector<int> pre(n1);
        int sum =0;
        for(int i = 0;i<n1;i++){
            sum+=nums[i];
            pre[i] = sum;
        }
        // for(int i:pre) cout<<i<<" ";
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        int dp[n1];
        dp[n1-1] = pre[n1-1];
        for(int i = n1-2;i>0;i--){
            dp[i] = max(dp[i+1],pre[i]-dp[i+1]);
        }
        return dp[1];

    }
};