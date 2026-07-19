class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> mp;
        for(char c:s) mp[c]++;
        stack<char> st;
        vector<bool> visited(26, false);
        for(char c:s){
            mp[c]--;
            if (visited[c-'a']) continue;
            while (!st.empty() && c<st.top() && mp[st.top()]>0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            visited[c - 'a'] = true;

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