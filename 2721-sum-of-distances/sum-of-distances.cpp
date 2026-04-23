class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < n; i++) {
            hash[nums[i]].push_back(i); 
        }
        vector<long long> arr(n, 0);
        for (auto& entry : hash) {
            vector<int>& v = entry.second;
            int m = v.size();
            long long total = 0;
            for (int i = 0; i < m; i++) {
                total += v[i];
            }
            long long pre= 0;
            for (int i = 0; i < m; i++) {
                long long curr = v[i];
                long long left = (long long)i * curr - pre;
                long long right = (total - pre - curr) -
                                  (long long)(m - 1 - i) * curr;

                arr[curr] = left + right;

                pre += curr;
            }
        }
        return arr;
    }
};