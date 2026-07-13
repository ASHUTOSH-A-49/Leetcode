class Solution {
public:
//approach  - 2: greedily use monotonic stack to get NSE and PSE
//must watch video to undertand the approach and intuition for this
    
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
};