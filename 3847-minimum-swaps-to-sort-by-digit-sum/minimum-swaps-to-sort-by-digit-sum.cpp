class Solution {
public:
    int digsum(int n) {
        n = abs(n);
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> start_pos;
        for (int i = 0; i < n; i++) {
            start_pos[nums[i]] = i;
        }
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; i++) {
            sorted_nums[i] = {digsum(nums[i]), nums[i]};
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int> assigned_target(n);
        for (int i = 0; i < n; i++) {
            int original_val = sorted_nums[i].second;
            int original_idx = start_pos[original_val];
            assigned_target[original_idx] = i;
        }
        vector<bool> vis(n, false);
        int totalSwaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || assigned_target[i] == i) 
                continue;

            int cycle_size = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = assigned_target[j];
                cycle_size++;
            }
            if (cycle_size > 0) {
                totalSwaps += (cycle_size - 1);
            }
        }

        return totalSwaps;
    }
};