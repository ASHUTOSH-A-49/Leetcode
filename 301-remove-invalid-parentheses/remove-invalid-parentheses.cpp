class Solution {
public:
    void solve(int idx, string &temp, string &s, int rem, int k, int balance, set<string> &ans) {
        if (rem > k || balance < 0) return;
        
        if (idx == s.size()) {
            if (balance == 0 && rem == k) {
                ans.insert(temp);
            }
            return;
        }
        
        if (s[idx] == '(' || s[idx] == ')') {
            solve(idx + 1, temp, s, rem + 1, k, balance, ans);
            
            temp.push_back(s[idx]);
            int next_balance = balance + (s[idx] == '(' ? 1 : -1);
            solve(idx + 1, temp, s, rem, k, next_balance, ans);
            temp.pop_back();
        } else {
            temp.push_back(s[idx]);
            solve(idx + 1, temp, s, rem, k, balance, ans);
            temp.pop_back();
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int minrem = 0;
        stack<char> st;
        for (char c : s) {
            if (c == '(') st.push(c);
            if (c == ')') {
                if (st.empty()) minrem++;
                else st.pop();
            }
        }
        minrem += st.size();
        
        set<string> ans;
        string temp = "";
        solve(0, temp, s, 0, minrem, 0, ans);
        
        vector<string> fans(ans.begin(), ans.end());
        return fans;
    }
};