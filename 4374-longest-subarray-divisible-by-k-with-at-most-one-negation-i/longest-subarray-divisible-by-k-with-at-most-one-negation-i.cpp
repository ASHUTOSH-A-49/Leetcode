class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<bool>> checksub;

    int solve(int l,int r){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int siz = 0;
        if(checksub[l][r]){
            siz = r-l+1;
        }
        int l1 = solve(l+1,r);
        int r1 = solve(l,r-1);

        return dp[l][r] = max({siz,l1,r1});
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        dp.assign(n,vector<int> (n,-1));
        checksub.assign(n,vector<bool>(n,false));

        for(int i = 0;i<n;i++){
            long long sum = 0;
            vector<bool> seen(k,false);
            for(int j = i;j<n;j++){
                sum+=nums[j];
                long long rem = (2*nums[j]%k+k)%k;
                seen[rem] = true;
                long long tot_rem = (sum%k+k)%k;

                if(tot_rem==0 || seen[tot_rem]){
                    checksub[i][j] = true;
                }
            }
        }
        return solve(0,n-1);
        
    }
    
};