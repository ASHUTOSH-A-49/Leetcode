class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        vector<int> nums2 = nums;
        nums2.insert(nums2.end(), nums.begin(), nums.end());
        int n2 = nums2.size();
        vector<int> NGE(n2);
        for(int i = n2-1;i>=0;i--){
            while(!(st.empty())&& st.top()<=nums2[i]) st.pop();
            if(st.empty()) NGE[i] = -1;
            else NGE[i] = st.top();
            st.push(nums2[i]); //psh to maintain NGE and monotonicity logic together
        }
        
        for(int i = 0;i<n;i++){
            ans[i] = NGE[i];
        }
        return ans;
    }
};