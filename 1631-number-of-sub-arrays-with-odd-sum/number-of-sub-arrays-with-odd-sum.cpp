class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        long long pref = 0;
        long long o = 0;
        for (int i : arr) {
            pref += i;
            o += pref % 2;
        }

        o += ((long long)arr.size() - o) * o;

        return o % MOD;
    }
};