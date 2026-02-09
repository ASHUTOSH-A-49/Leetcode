class Solution {
public:
    int minimumDeletions(string s) {
        int delelem = 0;
        int cntb = 0;
        for (char c : s) {
            if (c == 'b') {
                cntb++;
            } else if (cntb > 0) {
                delelem++;
                cntb--;
            }
        }
        return delelem;
    }
};