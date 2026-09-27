class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char c:s){
            if(c==')'){
                queue<char> s1;
                while(st.top()!='('){
                    s1.push(st.top());
                    st.pop();
                }
                st.pop(); // pop open brac
                while(!s1.empty()){
                    st.push(s1.front());
                    s1.pop();
                }
            }else{
                st.push(c);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
};