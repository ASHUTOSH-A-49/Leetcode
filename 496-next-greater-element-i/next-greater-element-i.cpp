class Solution {
public:
//APPROACH -2:monotonous stack+ hash
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> NGE; //as says distinct int so we can use map
        stack<int> st;
        int n = nums2.size();
        for(int i = n-1;i>=0;i--){
            //maintain monotonocity
            while(!(st.empty())&& st.top()<nums2[i]) st.pop();
            if(st.empty()) NGE[nums2[i]] = -1;
            else NGE[nums2[i]] = st.top();
            st.push(nums2[i]); //psh to maintain NGE and monotonicity logic together
        }
        for(int i:nums1){
            ans.push_back(NGE[i]);
        }
        return ans;
    }
};