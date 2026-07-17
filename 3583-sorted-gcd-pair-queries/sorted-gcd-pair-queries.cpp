typedef long long ll;
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n  = nums.size();
        int maxi = *max_element(begin(nums),end(nums));
        //inclusion exclusion principle
        vector<int> factFreq(maxi+1);
        for(int i = 0;i<n;i++){
            int num = nums[i];
            for(int j = 1;j*j <=num;j++){
                if(num%j==0){
                    factFreq[j]++;
                    if(num/j!=j)factFreq[num/j]++;
                }
                
            }
        }

        vector<ll> GCDpairs(maxi+1,0);
        for(int f = maxi;f>=1;f--){
            ll cnt = factFreq[f];
            //nC2;
            GCDpairs[f] = cnt*(cnt-1)/2;

            //corrn
            for(int mul = 2*f;mul<=maxi;mul+=f){
                GCDpairs[f]-=GCDpairs[mul];
            }
        }
        //sorted order of GCD
        vector<ll> preGcd(maxi+1,0);
        for(int f = 1;f<=maxi;f++){
            preGcd[f] = preGcd[f-1]+GCDpairs[f];
        }

        //BS
        vector<int> res;
        for(ll idx:queries){
            int l = 1,r = maxi,ans = 1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(preGcd[mid]>idx){
                    ans = mid;
                    r = mid-1;
                }else l = mid+1;
            }
            res.push_back(ans);
        }
        return res;
    }
};
