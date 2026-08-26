class Solution {
public:
void trimZerosInPlace(string &str) {
    size_t last = str.find_last_not_of('0');
    if (last != string::npos) {
        str.erase(last + 1);
    } else {
        str = "0";
        return;
    }
    size_t first = str.find_first_not_of('0');
    if (first != string::npos && first > 0) {
        str.erase(0, first);
    }
}
    string shortestBeautifulSubstring(string s, int k) {
        int c1 = 0;
        int l = 0,r = 0;
        int n = s.size();
        string ans = "";
        while(r<n && l<=r){
            if(s[r]=='1')c1++;
            while(c1>k){
                if(s[l]=='1') c1--;
                l++;
            }
            if(c1==k){
                string sub = s.substr(l,r-l+1);
                trimZerosInPlace(sub);
                if(ans=="") ans = sub;
                else {
                    if(sub.size()<ans.size()){
                        ans = sub;
                    }else{
                        if(sub.size()==ans.size()){
                            if(sub<ans) ans = sub;
                        }
                    }
                }
            }
            r++;
        }
        return ans;
    }
};