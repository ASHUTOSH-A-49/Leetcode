class Solution {
public:
    bool check(vector<int>& monsters,vector<long long> &boost,long long st){
        int n = monsters.size();
        for(int i = 0;i<n;i++){
            int m = monsters[i];
            if(st+boost[i]>=m){
                st = st-m;
            }else return false;
            if(st<0) st = 0;
            
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> diff(n+1,0);
        for(auto b:boosts){
            int l = b[0],r = b[1],val = b[2];
            diff[l]+=val;
            diff[r+1]-=val;
        }
        vector<long long> boost(n,0);
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum+=diff[i];
            boost[i]+=sum;
        }
        long long ans = 1e18,r = 1e18,l = 0;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(check(monsters,boost,mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};