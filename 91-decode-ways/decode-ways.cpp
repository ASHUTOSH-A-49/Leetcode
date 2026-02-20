class Solution {
public:
    int solve(string &s, int ind, vector<int> &memoiz) {
        if (ind == s.size()) return 1;
        if (memoiz[ind] != -1) return memoiz[ind];
        int totalWays = 0;


        string sub1 = "";
        sub1 += s[ind];
        int num1 = stoll(sub1);
        if (num1 >= 1 && num1 <= 9) { 
            totalWays += solve(s, ind + 1, memoiz);
        }
        if (ind + 1 < s.size()) {
            string sub2 = s.substr(ind, 2);
            int num2 = stoll(sub2);
            if (num2 >= 10 && num2 <= 26) {
                totalWays += solve(s, ind + 2, memoiz);
            }
        }

        return memoiz[ind] = totalWays;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> memoiz(s.size() + 1, -1);
        return solve(s, 0, memoiz);
    }
};
