class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> mul, div;
        for (int i : nums) {
            long long el = (long long)i * k;
            mul.push_back(el);
        }
        for (int i : nums) {
                div.push_back(i/k);
        }
        vector<long long> premul(n + 1, 0), prediv(n + 1, 0), prenum(n + 1, 0);
        long long mulsum = 0, divsum = 0, numsum = 0;
        for (int i = 0; i < n; ++i) {
            mulsum += mul[i];
            premul[i + 1] = mulsum;
    
            divsum += div[i];
            prediv[i + 1] = divsum;
            
            numsum += nums[i];
            prenum[i + 1] = numsum;
        }
        
        vector<long long> min_P(n + 1, 0);
        long long premin = 0;
        for (int i = 0; i <= n; ++i) {
            premin = min(premin, prenum[i]);
            min_P[i] = premin;
        }
        
        vector<long long> minexp_mul(n + 1,0), minexp_div(n + 1, 0);
        long long minmul = 0, minsumd = 0;
        for (int i = 0; i <= n; ++i) {
            long long currmul = premul[i]-prenum[i]+min_P[i];
            minmul = i == 0 ? currmul :min(minmul,currmul);
            minexp_mul[i] = minmul;

            long long currsumd = prediv[i]-prenum[i]+min_P[i];
            minsumd = i==0?currsumd :min(minsumd, currsumd);
            minexp_div[i] = minsumd;
        }
        
        vector<long long> max_P(n + 1, 0);
        long long opmax = prenum[n];
        for (int i = n; i >= 0; --i) {
            opmax = max(opmax, prenum[i]);
            max_P[i] = opmax;
        }
        
        long long maxmul = LLONG_MIN, maxsumd = LLONG_MIN;
        for (int i = 1; i <= n; ++i) {
            maxmul = max(maxmul, max_P[i]+premul[i]-prenum[i]-minexp_mul[i-1]);
            maxsumd = max(maxsumd, max_P[i]+prediv[i]-prenum[i]-minexp_div[i-1]);
        }
        
        long long maxsum = max(maxmul, maxsumd);
        if (n>1) {
            long long currsum = 0;
            opmax = LLONG_MIN;
            for (int i = 0; i < n - 1; ++i) {
                currsum = max((long long)nums[i], currsum + nums[i]);
                opmax = max(opmax, currsum);
            }
            currsum = 0;
            for (int i = 1; i < n; ++i) {
                currsum = max((long long)nums[i], currsum + nums[i]);
                opmax = max(opmax, currsum);
            }
            maxsum = max(maxsum, opmax);
        }
        
        return maxsum;
    }
};