class Solution {
public:
    int BsUbIdx(vector<int> &lights,int target){
        int ans = -1,l = 0,r = lights.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(lights[mid]>target){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        sort(lights.begin(),lights.end());
        sort(arrivalTime.begin(),arrivalTime.end());
        int maxpen = 0;
        for(int i :arrivalTime){
            int mod = i%period;
            int idx = BsUbIdx(lights,mod);
            if(idx==-1) maxpen = max(maxpen,period-mod);
        }
        return maxpen;
    }
};