class KthLargest {
public:
//CONCEPT - keep k window in min heap if size exceeds k pop
priority_queue<int,vector<int>,greater<int>> pq;
int k1;
    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        for(int i: nums) add(i);
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k1) pq.pop();// if size exceeds that means a greater value is addded hence to maintain window remove the smaller one existing in window i.e. top
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */