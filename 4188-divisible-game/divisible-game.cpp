#define ll long long
class Solution {
public:
    int MOD = 1e9 + 7;
    ll MaxSc(vector<int> & nums,int k){
        ll maxi = -1e18,curr = 0;
        for(int i:nums){
            ll d = i%k;
            ll val;
            if(d==0) val = i;
            else val = -i;
            curr+=val;
            if(curr>maxi){
                maxi = curr;
            }
            if(curr<0){
                curr = 0;
            }
        }
        return maxi;
    }
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        set<int> divs;
        divs.insert(2);
        for(int i:nums){
            int maxD = sqrt(i);
            if(i>1) divs.insert(i);
            for(int j = 2;j<=maxD;j++){
                if(i%j==0){
                    divs.insert(j);
                    divs.insert(i/j);
                }
            }
        }
        ll diffans = -1e18;
        ll maxK = 2;
        for(int k:divs){
            ll curr = MaxSc(nums,k);
            if(curr>diffans){
                diffans = curr;
                maxK = k;
            }
        }

        ll res = (diffans * maxK);
        int ans = (res%MOD + MOD)%MOD;
        return ans;
    }
};