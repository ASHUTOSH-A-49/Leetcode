class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = 0,r = needle.size()-1;
        if(r>=haystack.size()) return -1;
        while(r<haystack.size()){
            string sub = haystack.substr(l,r-l+1);
            if(sub==needle) return l;
            l++;r++;
        }
        return -1;
    }
};