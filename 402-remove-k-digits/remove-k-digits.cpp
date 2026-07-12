class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        string ans;
        // if there is a dip in number sequence we will catch it and remove it 
        for(int i=0;i<num.size();i++){
            char c = num[i];
            int n = c-'0';
            while(!st.empty()&&n<st.top()&&k>0){
                k--;
                st.pop();
            }
            st.push(n);
        }
        //if no dip in digits i.e. monotonic increasing
        while(k>0&&!st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size()&&ans[i]=='0') i++;
        ans=ans.substr(i);
        if(ans.size()==0) return "0";
        return ans;
    }
};