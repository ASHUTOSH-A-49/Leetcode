class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            char c = s[i];
            if(c=='('){
                st.push(c);
            }else{
                if(i+1<n){
                    char c1 = s[i+1];
                if(c1==')'){
                    if(st.empty()) ans++; //insert left for 2 consec right
                    else st.pop(); // balance 2 consec right
                    i++;
                }else{
                    //not 2 consec right
                    if(st.empty()){
                        //if no left is there then add () to make 2 right for 1 left
                        ans+=2;

                    }else{
                        //if a left is already there , then add 1 right to balance the left
                        st.pop();
                        ans++;
                    }
                }
                
                }else{
                    if(st.empty()) ans+=2;
                    else{
                        st.pop();
                        ans++;
                    } 
                }
                
            }
        }
        ans+=2*st.size();
        return ans;
    }
};