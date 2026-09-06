class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> st;
        for(int i:nums) st.insert(i);
        int len = 1,maxlen = 0;
        long long mini = -1e9-1;
        long long prev = mini;
        for(int i:st){
            if(prev==mini) {
                prev = i;
                continue;
            }
            if(i-prev==1)len++;
            else {
                maxlen = max(maxlen,len);
                len = 1;

            }
            prev = i;
        }
        maxlen = max(maxlen,len);
        return maxlen;
    }
};