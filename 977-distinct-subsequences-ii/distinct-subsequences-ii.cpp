typedef pair<int,string> pis;
class Solution {
public:
    int MOD = 1e9+7;
    int dp[2001];
    long long solve(int n,vector<int> & prev){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        long long total = (2*solve(n-1,prev))%MOD;
        long long dupl = 0;
        if(prev[n-1]>=0) dupl = solve(prev[n-1],prev);
        long long res = (total-dupl+MOD)%MOD;
        return dp[n] = res;
    }
    int distinctSubseqII(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        vector<int>  prev(n,-1);
        map<char,int> mp;
        for(int i = 0;i<n;i++){
            char c = s[i];
            if(mp.count(c)) prev[i] = mp[c];
            mp[c] = i;
        }
        long long res = solve(n,prev);
        return (res-1+MOD)%MOD;
    }
};