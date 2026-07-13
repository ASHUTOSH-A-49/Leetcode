class Solution {
public:
//approach  - 1 : use PSE and NSE and then get to every bar and get its rectangle size
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
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int,int>> PSE = getPSE(heights);
        vector<pair<int,int>> NSE = getNSE(heights);

        int n=  heights.size(),maxi = 0;
        for(int i = 0;i<n;i++){
            int h = heights[i];
            int pseidx = PSE[i].second,nseidx = NSE[i].second;
            // (nseidx-1)-(pseidx+1) +1
            int b = nseidx-pseidx-1;
            maxi = max(maxi,h*b);
        }
        return maxi;
    }
};