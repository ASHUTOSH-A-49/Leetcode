class Solution {
public:
//APPROACH -1 : 2 stack approach
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st1,st2;
        for(int i:nums2) st1.push(i);
        for(int i:nums1){
            int nextgr = -1;
            while(st1.top()!=i){
                if(st1.top()>i){
                    nextgr = st1.top();
                }
                st2.push(st1.top());
                st1.pop();
            }
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
            ans.push_back(nextgr);
        }
        return ans;
    }
};