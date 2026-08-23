class Solution {
public:
    string asctoBin(int n){
        string res="";
        stack<char> st;
        while(n>0){
            int rem = n%2;
            (rem==0)?st.push('0'):st.push('1');
            n/=2;
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
            
        }
        int siz = 8-(int)(res.size());
        string lead = "";
        for(int i = 0;i<siz;i++){
            lead+='0';
        }
        return lead+res;
        
    }
    bool isPal(string &s){
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
    bool isPalindromic(string s) {
        string res = "";
        for(char c:s){
            int ch = c;
            res+=asctoBin(ch);
        }
        return isPal(res);
        
    }
};