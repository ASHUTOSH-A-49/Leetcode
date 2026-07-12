class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i = n-1;i>=0;i--){
            int b = asteroids[i];
            bool dest = false;
            if(!st.empty()){
                while(!st.empty()&& st.top()<0 && b>0 && b>=abs(st.top())){
                    if(b==abs(st.top())) dest = true;
                    st.pop();
                    if(dest) break;
                }
            }
            if(!st.empty() && st.top()<0 && b>0 && b<abs(st.top())){
                //dont push
            }else{
                if(!dest)
                st.push(b);
            }
            
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};