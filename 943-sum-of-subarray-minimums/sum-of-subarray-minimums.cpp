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
        int n = arr.size();
        int MOD = 1e9 + 7;
        stack<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                long long lb = st.empty() ? -1 : st.top();
                long long rb = i;
                long long l = mid - lb;
                long long r = rb - mid;
                long long sub = (l * r) % MOD;
                long long res = (sub * arr[mid]) % MOD;
                ans = (ans + res) % MOD;
            }
            st.push(i);
        }
        return ans;
    }
};