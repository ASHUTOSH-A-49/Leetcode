class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int pre = 0;
        int curr = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i - 1] != s[i]) {
                ans += min(pre, curr);
                pre = curr;
                curr = 1;
            } else {
                curr++;
            }
        }
        // int ans2 = min(pre, curr);
        return ans + min(pre, curr);
    }
};