using ll = long long;

class Solution {
public:
    ll getDigMax(int n){
        ll ans = 0;
        vector<int> digs(10,0);
        while(n>0){
            digs[n%10]++;
            n/=10;
        }
        for(int i = 9;i>=0;i--){
            while(digs[i]>0){
                ans = ans*10+i;
                digs[i]--;
            }
        }
        return ans;
        
    }
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        vector<pair<ll,int>> del(n);
        
        for(int i = 0;i<n;i++){
            ll maxd = getDigMax(nums[i]);
            del[i] = {maxd-nums[i],i};
        }
        sort(del.begin(),del.end(),[](auto&a,auto&b){
            return a.first>b.first;
        });
        for(int i = 0;i<k;i++){
            int idx= del[i].second;
            sum+=getDigMax(nums[idx]);
            nums[idx] = 0;
        }
        for(int i:nums){
            sum+=i;
        }
        return sum;
        
    }
};