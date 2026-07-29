class Solution {
public:
    const long long MAX_K = 1000001;

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r;
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res >= MAX_K) return MAX_K;
        }
        return res;
    }

    long long countPermutations(int remainingLen, const map<int, int>& freq) {
        long long count = 1;
        int currentLen = remainingLen;

        for (auto const& [val, f] : freq) {
            if (f > 0) {
                if (f > currentLen) return 0;
                count = min(MAX_K, count * nCr(currentLen, f));
                currentLen -= f;
            }
        }
        return count;
    }

    vector<int> getKthMultisetPermutation(vector<int> nums, long long k) {
        int n = nums.size();
        map<int, int> freq;
        for (int x : nums) freq[x]++;

        long long totalPerms = countPermutations(n, freq);
        if (k > totalPerms) return {};

        k--;
        vector<int> result;

        for (int pos = 0; pos < n; ++pos) {
            int remainingLen = n - 1 - pos;

            for (auto& [val, count] : freq) {
                if (count == 0) continue;

                freq[val]--;
                long long numPerms = countPermutations(remainingLen, freq);

                if (k >= numPerms) {
                    k -= numPerms;
                    freq[val]++;
                } else {
                    result.push_back(val);
                    break;
                }
            }
        }

        return result;
    }

    string smallestPalindrome(string s, long long k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> v;
        for (int i = 0; i < 26; i++) {
            int h = freq[i] / 2;
            for (int j = 0; j < h; j++) {
                v.push_back(i);
            }
        }

        if (v.empty()) {
            return (k == 1) ? s : "";
        }

        v = getKthMultisetPermutation(v, k);

        if (v.empty()) return "";

        string s1 = "";
        for (int i : v) {
            s1 += (i + 'a');
        }

        string mid = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                mid += (i + 'a');
                break;
            }
        }

        string s2 = s1;
        reverse(s2.begin(), s2.end());

        return s1 + mid + s2;
    }
};