class Solution {
public:
    int path(int st, int fin, vector<long long> &prefl, vector<long long> &prefr) {
        if (st < fin) {
            return prefl[fin] - prefl[st];
        } else {
            return prefr[fin] - prefr[st];
        }
    }

    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans(queries.size());
        vector<int> closest(n);
        vector<long long> prefl(n, 0);
        vector<long long> prefr(n, 0);

        closest[0] = 1;
        closest[n - 1] = n - 2;
        for (int i = 1; i < n - 1; i++) {
            if (abs(nums[i] - nums[i - 1]) > abs(nums[i] - nums[i + 1])) closest[i] = i + 1;
            else closest[i] = i - 1;
        }
        for (int i = 1; i < n; i++) {
            int cost = (closest[i - 1] == i) ? 1 : abs(nums[i] - nums[i - 1]);
            prefl[i] = prefl[i - 1] + cost;
        }

        for (int i = n - 2; i >= 0; i--) {
            int cost = (closest[i + 1] == i) ? 1 : abs(nums[i] - nums[i + 1]);
            prefr[i] = prefr[i + 1] + cost;
        }
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = path(queries[i][0], queries[i][1], prefl, prefr);
        }

        return ans;
    }
};