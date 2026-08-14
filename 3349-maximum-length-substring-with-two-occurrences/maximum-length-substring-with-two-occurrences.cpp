class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26,0);
        int l = 0,r = 0,maxlen = 0,n = s.size();
        while(r<n){
            char c = s[r] -'a';
            freq[c]++;
            while(freq[c]>2){
                char c2 = s[l]-'a';
                freq[c2]--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;

    }
};