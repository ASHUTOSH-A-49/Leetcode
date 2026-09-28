class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //approach  - using multiset
        multiset<int,greater<int>> st;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0;i<k;i++){
            st.insert(nums[i]);
        }
        // 3,1,-1
        int el = *st.begin();
        ans.push_back(el);
        int l = 0,r = k;
        while(r<n){
            auto it = st.find(nums[l]);
            if (it != st.end()) {
                st.erase(it); 
            }
            st.insert(nums[r]);
            l++;r++;
            int el1 = *st.begin();
            ans.push_back(el1);
        }
        return ans;
    }
};