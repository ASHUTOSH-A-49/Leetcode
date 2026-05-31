class Solution {
public:
    int memo[1001][1505];
    int free_counts[1001];
    int mini;
    int solve(vector<vector<int>>& items, int budget, int idx, int curr) {
        if (idx == items.size()) {
            int newbud = budget - curr;
            return newbud / mini;
        }
        
        if (memo[idx][curr] != -1) {
            return memo[idx][curr];
        }
        
        int skip = solve(items, budget, idx + 1, curr);
        int buy = 0;
        
        if (curr + items[idx][1] <= budget) {
            buy = 1 + free_counts[idx] + solve(items, budget, idx + 1, curr + items[idx][1]);
        }
        
        return memo[idx][curr] = max(skip, buy);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        memset(free_counts, 0, sizeof(free_counts));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[i][0] != 0 && items[j][0] % items[i][0] == 0) {
                    free_counts[i]++;
                }
            }
        }

        mini = 1505;
        for (int i = 0; i < n; i++) {
            mini = min(mini, items[i][1]);
        }

        memset(memo, -1, sizeof(memo));
        return solve(items,budget,0,0);
    }
};