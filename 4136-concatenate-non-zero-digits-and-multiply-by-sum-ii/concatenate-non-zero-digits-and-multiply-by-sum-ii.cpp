int MOD = 1e9+7;
typedef long long ll;
class Solution {
public:
int getDig(int n){
    int cnt = 0;
    while(n){
        n = n/10;
        cnt++;
    }
    return cnt;
}
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        //APPROACH -2 : PREFIX ARRAYS and MATHS
        int n = s.size();
        int sum = 0;
        vector<int> preSum(n), preDig(n), non0(n);
        vector<ll> power10(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            power10[i] = (power10[i-1]*10)%MOD;
        }
        int activeCount = 0;
        for(int i =0;i<n;i++){
            int d = s[i]-'0';
            sum+=d;
            preSum[i] = sum;
            if(d!=0) activeCount++;
            non0[i] = activeCount;
            if(i == 0) {
                preDig[i] = d;
            } else {
                if(d==0) preDig[i]=preDig[i-1];
                else preDig[i] = (1LL*preDig[i-1]*10+d) % MOD;
            }
        }
        vector<int> ans;
        for(vector<int> q : queries){
            int l = q[0], r = q[1];
            ll res;
            if(l == 0) {
                res = (1LL*preDig[r]*preSum[r])%MOD;
            } else {
                int shift = non0[r]-non0[l-1]; 
                ll rangeSum = preSum[r]-preSum[l-1]; 
                ll x = (preDig[r]-(1LL*preDig[l-1]*power10[shift])% MOD+MOD)%MOD;
                res = (x*rangeSum) % MOD;
            }
            ans.push_back(res);
        }
        return ans;

    }
};