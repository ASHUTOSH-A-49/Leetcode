class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < k) {
            return false;
        }
        unordered_set<string> hashset;
        for (int i =0; i<=s.length()-k;i++) {
            hashset.insert(s.substr(i, k));
            if (hashset.size() == (1 << k)) {
                return true;
            }
        }
        return hashset.size() == (1 << k);
    }
};