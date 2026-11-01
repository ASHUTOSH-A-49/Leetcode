class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i,int &n,string & s,string s1,map<string,int> &mp){
        int j = s1.size();
        if(i==n){
            if(s1.size()>0){
            if(mp.count(s1)) return true;
                return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        s1+=s[i];
        if(mp.count(s1)){
            bool keep = solve(i+1,n,s,s1,mp);
            bool rem = solve(i+1,n,s,"",mp);
            return dp[i][j] = keep || rem;
        }
        return dp[i][j] = solve(i+1,n,s,s1,mp);

    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        dp.assign(n, vector<int>(n + 1, -1));
        map<string,int> mp;
        for(string s1:wordDict){
            mp[s1]++;
        }
        return solve(0,n,s,"",mp);
    }
};