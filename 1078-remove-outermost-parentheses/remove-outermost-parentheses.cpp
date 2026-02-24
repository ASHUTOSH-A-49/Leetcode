class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<char> ans;
        int lp = 0,rp = 0,sind = -1;

        for(int i = 0;i<s.size();i++){
            if(s[i]=='(')lp++;
            else rp++;
            if(lp==rp){
                lp = 0;rp = 0;
                ans[sind] = '0';
                ans.push_back('0');
            } 
            else ans.push_back(s[i]);
            if(lp==1) sind = i;
        }
        string ansstr = "";
        for(char c:ans){
            if(c=='0')continue;
            else ansstr+=c;
        }
        return ansstr;
    }
};