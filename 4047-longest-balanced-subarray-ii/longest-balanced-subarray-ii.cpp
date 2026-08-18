class SegTree{
    int n;
    vector<int> StreeMin;
    vector<int> StreeMax;
    vector<int> lazy;
    void push(int idx, int l, int r) {
        if (lazy[idx] != 0) {
            StreeMin[idx] += lazy[idx];
            StreeMax[idx] += lazy[idx];
            if (l != r) { 
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }
    void BuildTree(vector<int> & arr,int idx,int l,int r){
        if(l==r){
            //BASE CASE
            StreeMin[idx] = arr[l];
            StreeMax[idx] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        BuildTree(arr,2*idx+1,l,mid); //go left node -recursion
        BuildTree(arr,2*idx+2,mid+1,r); //go right node -recursion
        StreeMin[idx] = min(StreeMin[2 * idx + 1], StreeMin[2 * idx + 2]);
        StreeMax[idx] = max(StreeMax[2 * idx + 1], StreeMax[2 * idx + 2]); //building tree
    }

    int RangeQuery(int idx, int l, int r, int start, int end) {
        push(idx, l, r);
        // Out of bounds or the minimum value in this segment is greater than 0
        if (r < start || l > end || 0 < StreeMin[idx] || 0 > StreeMax[idx]) {
            return 1e6; 
        }
        // Leaf node reached
        if (l == r) {
            return (StreeMin[idx] == 0) ? l : 1e6;
        }
        int mid = l + (r - l) / 2;
        // Check left subtree first to ensure we get the absolute leftmost index
        int leftRes = RangeQuery(2 * idx + 1, l, mid, start, end);
        if (leftRes != 1e6) {
            return leftRes;
        }
        // If not found in the left subtree, check the right subtree
        return RangeQuery(2 * idx + 2, mid + 1, r, start, end);
    }

    void updateRangeMin(int idx, int l, int r, int start, int end, int val) {
        push(idx, l, r);
        if (r < start || l > end) {
            return;
        }
        if (l >= start && r <= end) {
            lazy[idx] += val;
            push(idx, l, r);
            return;
        }
        int mid = l + (r - l) / 2;
        updateRangeMin(2 * idx + 1, l, mid, start, end, val);
        updateRangeMin(2 * idx + 2, mid + 1, r, start, end, val);
        
        StreeMin[idx] = min(StreeMin[2 * idx + 1], StreeMin[2 * idx + 2]);
        StreeMax[idx] = max(StreeMax[2 * idx + 1], StreeMax[2 * idx + 2]);
    }

    public:
    SegTree(vector<int> & nums){
        n = nums.size();
        StreeMin.assign(4 * n, 0); 
        StreeMax.assign(4 * n, 0); 
        lazy.assign(4*n,0);
        if (n>0) BuildTree(nums,0,0, n-1);
    }
    int getRange(int start,int end){
        return RangeQuery(0, 0, n - 1, start, end);
    }
    void updateRange(int start,int end,int val){
        updateRangeMin(0, 0, n - 1, start, end, val);
    }
};


class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        vector<int> cumSum(n,0);
        SegTree st(cumSum);
        int maxL = 0;
        unordered_map<int,int> mp;
        for(int r = 0;r<n;r++){
            //even as +1 , odd as -1
            int val = (nums[r]%2==0) ?1 :-1;

            int prev = -1;
            if(mp.count(nums[r])) prev = mp[nums[r]];
            if(prev!=-1){
                //we have seen this before 
                // [0... prev] -val 
                st.updateRange(0,prev,-val);
            }

            // [0... r] +val 
            st.updateRange(0,r,val);
            // get left most 0 in 0.. r 
            int l = st.getRange(0,r);
            if(l!=1e6) maxL = max(maxL,r-l+1);
            mp[nums[r]] = r; //update map
        }

        return maxL;
    }
};