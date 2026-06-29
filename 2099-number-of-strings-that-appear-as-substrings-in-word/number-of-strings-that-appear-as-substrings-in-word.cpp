class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(string s:patterns){
            int n = s.size();
            int l = 0,r = n-1;
            while(r<word.size()){
                string sub = word.substr(l,r-l+1);
                if(sub==s) {
                    cnt++;
                    break;
                }
                l++;r++;
            }
        }
        return cnt;
    }
};