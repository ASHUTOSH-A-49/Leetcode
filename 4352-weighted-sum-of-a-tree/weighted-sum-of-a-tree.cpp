class Solution {
public:
    int getlev(int i,vector<int>& par,vector<int>&lev){
        if(par[i]==-1) return 0;
        if(lev[i]!=-1) return lev[i];
        lev[i] = getlev(par[i],par,lev)+1;
        return lev[i];
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<int> lev(n,-1);
        int maxlev = 0;
        for(int i = 0;i<n;i++){
            lev[i] = getlev(i,parent,lev);
            maxlev = max(maxlev,lev[i]);
            
        }

        int h = maxlev+1;
        long long sum = 0;
        for(int i = 0;i<n;i++){
            //depth = lev[i]+1
            long long res = (long long) nums[i]*(h-lev[i]);
            sum+=res;
        }
        return sum;

        
    }
};