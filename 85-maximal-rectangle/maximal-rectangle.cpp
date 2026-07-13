class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int n=  heights.size(),maxi = 0;
        for(int i = 0;i<n;i++){
            int h = heights[i];
            int nse  = i;
            while(!st.empty() && st.top().first>h){
                auto p  = st.top();
                st.pop();
                int pse = (st.empty()) ?-1 : st.top().second;
                int ar = (nse-pse-1)*p.first;
                maxi = max(maxi,ar);
                
            }
            st.push({h,i});
        }
        int nse = n;
        while(!st.empty()){
            auto p = st.top();
            st.pop();
            int pse = (st.empty()) ?-1 : st.top().second;
            int ar = (nse-pse-1)*p.first;
            maxi = max(maxi,ar);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        vector<vector<int>> preSum(m,vector<int>(n));
        for(int j = 0;j<n;j++){
            int pre = 0;
            for(int i = 0;i<m;i++){
                int c = matrix[i][j] - '0';
                if(c==0) pre = 0;
                else pre+=c;
                preSum[i][j] = pre;
            }
        }
        int maxi = 0;
        for(vector<int> v:preSum){
            maxi = max(largestRectangleArea(v),maxi);
        }
        return maxi;


    }
};