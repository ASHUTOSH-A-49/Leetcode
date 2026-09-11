class Solution {
public:
void solve(int cnt, int num, vector<int>& d, set<int>& st, vector<int>& vis) {
        if (cnt == 3) {
            if (num % 2 == 0) {
                st.insert(num);
            }
            return;
        }

        for (int i = 0; i < d.size(); i++) {
            if (!vis[i]) {
                if (cnt == 0 && d[i] == 0) continue; 

                vis[i] = 1;
                solve(cnt + 1, num * 10 + d[i], d, st, vis);
                vis[i] = 0;
                
            }
        }
}

    int totalNumbers(vector<int>& digits) {
        set<int> st;
        int n = digits.size();
        vector<int> vis(n, 0);
        
        solve(0, 0, digits, st, vis);
        
        return st.size();
        
    }
};