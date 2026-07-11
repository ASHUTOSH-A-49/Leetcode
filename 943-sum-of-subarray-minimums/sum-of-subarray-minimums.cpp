class Solution {
public:
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
    int sumSubarrayMins(vector<int>& arr) {
        vector<pair<int,int>> PSE = getPSE(arr);
        vector<pair<int,int>> NSE = getNSE(arr);
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            auto ps = PSE[i], ns = NSE[i];
            long long l = i - ps.second; 
            long long r = ns.second - i; 
            long long sub = (l * r) % MOD; 
            long long res = (sub * arr[i]) % MOD;
            ans = (ans + res) % MOD;
        }
        return ans;
    }
};