int pf[1000001];
void sieve(){
        for(int i = 1;i<1000001;i++){
            pf[i] = i;
        }
        for(int i = 2;i<1000001;i+=2){
            pf[i] = 2;
        }

        for(int i = 3;i*i<1000001;i+=2){
            if(pf[i]==i) {
                for(int j = i*i;j<1000001;j+=i){
                    if(pf[j]==j){
                        pf[j] = i;
                    }
                }
            }
        }
    }
class Solution {
public:
    vector<int> primeFac(int n){
        vector<int> fac;
        while(n>1){
            int p = pf[n];
            fac.push_back(p);
            while(n%p==0){
                n/=p;
            }
        }
        return fac;
    }
    int longestSubarray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sieve();
        unordered_map<int,int> mp;
        int n = nums.size();
        int l = 0,r = 0;
        int siz = 0;
        while(l<=r && r<n){
            vector<int> pfr = primeFac(nums[r]);
            for(int i:pfr) mp[i]++;
            while(mp.size()>k){
                vector<int> pfl = primeFac(nums[l]);
                for(int i:pfl) {
                    mp[i]--;
                    if(mp[i]==0) mp.erase(i);
                }
                l++;
            }
            siz = max(siz,r-l+1);
            r++;
        }
        return siz;
    }
};