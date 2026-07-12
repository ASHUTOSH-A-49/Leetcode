typedef long long ll;
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int MOD = 1e9+7;
        ll ans = 0;
        ll cost = 1;
        ll res = k;
        for(int i:nums){
            if(res<i){
                ll req = i-res;
                ll cnt = (req+k-1)/k;
                ll t1 = cost,t2 = cost+cnt-1;
                ll st = t1+t2;
                ll totcost;
                if(cnt%2==0){
                    totcost= (((cnt/2) % MOD) * (st%MOD))%MOD;
                }else{
                    totcost= ((cnt % MOD) * ((st/2)%MOD))%MOD;
                }
                ans = (ans+totcost)%MOD;
                cost= (cost+cnt);
                res+=cnt*k;
            }
            res = res-i;
        }
        return ans;
        
    }
};