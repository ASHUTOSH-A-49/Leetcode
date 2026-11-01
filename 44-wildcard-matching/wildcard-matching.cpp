class Solution {
public:
vector<vector<int>> dp;
bool solve(int i,int j,int &m,int &n,string & s,string &p){
    //base cases;
        if (i == m && j == n) return true;
        if (j == n) return false; 
        // If string finishes but pattern is left, it can only match if the rest of pattern is all '*'
        if (i == m) {
            for (int k = j; k < n; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (p[j] == '?' || s[i] == p[j]) {
            return dp[i][j] = solve(i + 1, j + 1, m, n, s, p);
        }
        // '*' case
        if (p[j] == '*') {
            // very important choiceeeeeeeeeeeee
            return dp[i][j] = solve(i, j + 1, m, n, s, p) || solve(i + 1, j, m, n, s, p);
        }
        return dp[i][j] = false;
    
}
    bool isMatch(string s, string p) {
        int m = s.size(),n = p.size();
        dp.assign(m,vector<int>(n,-1));
        return solve(0,0,m,n,s,p);
    }
};