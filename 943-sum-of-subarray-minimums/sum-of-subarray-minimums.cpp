class Solution {
public:
int MOD = 1e9+7;
int maxi  = 1e6;
    vector<pair<int,int>> getPSE(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<pair<int,int>> PSE(n);
        for(int i = 0;i<n;i++){
            while(!(st.empty())&& st.top().first>nums[i]) st.pop();
            if(st.empty()) PSE[i] = {maxi,0};
            else PSE[i] = st.top();
            st.push({nums[i],i+1}); //psh to maintain NSE and monotonicity logic together
        }
        return PSE;
    }
    vector<pair<int,int>> getNSE(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<pair<int,int>> NSE(n);
        for(int i = n-1;i>=0;i--){
            while(!(st.empty())&& st.top().first>=nums[i]) st.pop();
            if(st.empty()) NSE[i] = {maxi,n};
            else NSE[i] = st.top();
            st.push({nums[i],i}); //psh to maintain NSE and monotonicity logic together
        }
        return NSE;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<pair<int,int>> PSE,NSE;
        PSE = getPSE(arr);
        NSE = getNSE(arr);
        int n= arr.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            auto ps = PSE[i],ns = NSE[i];
            int l = i-ps.second+1;//left number till PSE idx
            int r = ns.second-i;//left number till NSE idx
            // cout<<l<<" "<<r<<endl;
            long long sub  = l*r; //number of subarrays in which num at idx i will be minimum
            long long res = (sub*arr[i])%MOD;
            // cout<<res<<endl;
            ans=(ans+res)%MOD;
        }
        return ans;
    }
};