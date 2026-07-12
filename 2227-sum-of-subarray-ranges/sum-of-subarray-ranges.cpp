class Solution {
public:
//APPROACH - derived from sum of subarr mins and derived from sum of subarr maxs
int MOD = 1e9 + 7;
    vector<pair<int,int>> getPSE(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<pair<int,int>> PSE(n);
        for(int i = 0; i < n; i++){
            while(!(st.empty()) && st.top().first > nums[i]) 
                st.pop();
            if(st.empty()) PSE[i] = {-1, -1}; 
            else PSE[i] = st.top();
            st.push({nums[i], i}); 
        }
        return PSE;
    }
    vector<pair<int,int>> getNSE(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<pair<int,int>> NSE(n);
        for(int i = n - 1; i >= 0; i--){
            while(!(st.empty()) && st.top().first >= nums[i]) 
                st.pop();
            if(st.empty()) NSE[i] = {-1, n}; 
            else NSE[i] = st.top();
            st.push({nums[i], i}); 
        }
        return NSE;
    }
    vector<pair<int,int>> getPGE(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<pair<int,int>> PGE(n);
        for(int i = 0; i < n; i++){
            while(!(st.empty()) && st.top().first < nums[i]) 
                st.pop();
            if(st.empty()) PGE[i] = {-1, -1}; 
            else PGE[i] = st.top();
            st.push({nums[i], i}); 
        }
        return PGE;
    }
    vector<pair<int,int>> getNGE(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<pair<int,int>> NGE(n);
        for(int i = n - 1; i >= 0; i--){
            while(!(st.empty()) && st.top().first <= nums[i]) 
                st.pop();
            if(st.empty()) NGE[i] = {-1, n}; 
            else NGE[i] = st.top();
            st.push({nums[i], i}); 
        }
        return NGE;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<pair<int,int>> PSE = getPSE(arr);
        vector<pair<int,int>> NSE = getNSE(arr);
        int n = arr.size();
        long long ans = 0;
        for(int i = 0; i < n; i++){
            auto ps = PSE[i], ns = NSE[i];
            long long l = i - ps.second; 
            long long r = ns.second - i; 
            long long sub = (l * r) ; 
            long long res = (sub * arr[i]) ;
            ans = (ans + res) ;
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int> & arr){
        vector<pair<int,int>> PGE = getPGE(arr);
        vector<pair<int,int>> NGE = getNGE(arr);
        int n = arr.size();
        long long ans = 0;
        
        for(int i = 0; i < n; i++){
            auto pg = PGE[i], ng = NGE[i];
            long long l = i - pg.second;
            long long r = ng.second - i;
            long long sub = (l * r);
            long long res = (sub * arr[i]);
            ans = (ans + res);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};