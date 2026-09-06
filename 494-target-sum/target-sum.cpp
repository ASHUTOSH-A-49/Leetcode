class Solution {
public:
//COUNT PARTITION WITH DIFF D PATTERN

int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int tot = 0;
        for(int i:arr) tot+=i;
        if(tot<abs(diff) || (tot+diff)&1) return 0;
        int target = (tot+diff)/2;
        
        vector<int>dp (target+1,0);
        //base case
        dp[0] = 1;
        if(arr[n-1]<=target) dp[arr[n-1]]++;
        for(int idx = n-2;idx>=0;idx--){
            for(int t = target;t>=0;t--){
                int take = 0;
                if(arr[idx]<=t) take = dp[t-arr[idx]];
                int skip = dp[t];
                dp[t] = skip+take;
            }
        }

        return dp[target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);


    }
};