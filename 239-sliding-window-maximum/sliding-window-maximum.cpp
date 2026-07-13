class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //approach -1: use monotonic decreasing dequeue and append answer while traversal and tracking k elements exact

        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            // Remove the front element if it is outside the current window boundary
            if (dq.front() == i - k) {
                dq.pop_front();
            }
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
        
    }
};