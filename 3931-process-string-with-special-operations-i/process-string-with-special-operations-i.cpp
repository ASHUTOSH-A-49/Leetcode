class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(int i = 0;i<s.size();i++){
            if(s[i]>=97 && s[i]<=122){
                res+=s[i];
            }
            else if(s[i]=='*'){
                if(res.size()>0) res.pop_back();
            }
            else if(s[i]=='#'){
                res+=res;
            }
            else if(s[i]=='%'){
                if(res.size()>0)
                reverse(res.begin(),res.end());
            }

        }
        return res;
    }
};