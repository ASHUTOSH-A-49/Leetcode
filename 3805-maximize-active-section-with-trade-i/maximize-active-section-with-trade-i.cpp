class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int maxcnt = 0, cnt = 0, l = -1, r = -1, first1 = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (cnt == 0) {
                    first1 = i;
                }
                cnt++;
                
                if (i == n - 1 || s[i + 1] == '0') {
                    int lb = -1, rb = n;

                    for (int j = first1 - 1; j >= 0; j--) {
                        if (s[j] == '1') { lb = j; break; }
                    }
                    for (int j = i + 1; j < n; j++) {
                        if (s[j] == '1') { rb = j; break; }
                    }

                    if (first1 > 0 && i < n - 1) {
                        int cnt1 = (rb - lb - 1) - cnt; 

                        if (cnt1 > maxcnt) {
                            maxcnt = cnt1;
                            l = first1;
                            r = i;
                        }
                    }
                    cnt = 0;
                }
            }
        }

        if (l == -1 && r == -1) {
            int cnt1 = 0;
            for (char c : s) {
                if (c == '1') cnt1++;
            }
            return cnt1;
        } else {
            int lb = 0, rb = n - 1;
            for (int i = l - 1; i >= 0; i--) {
                if (s[i] == '1') { lb = i; break; }
            }
            for (int i = r + 1; i < n; i++) {
                if (s[i] == '1') { rb = i; break; }
            }

            int cntact = rb - lb + 1;
            for (int i = 0; i < lb; i++) {
                if (s[i] == '1') cntact++;
            }
            for (int i = rb + 1; i < n; i++) {
                if (s[i] == '1') cntact++;
            }
            return cntact;
        }
    }
};