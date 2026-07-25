class SegTree{
    int n;
    vector<int> Stree;
    void BuildTree(vector<int> & arr,int idx,int l,int r){
        if(l==r){
            //BASE CASE
            Stree[idx] = arr[r];
            return;
        }
        int mid = (l+r)/2;
        BuildTree(arr,2*idx+1,l,mid); //go left node -recursion
        BuildTree(arr,2*idx+2,mid+1,r); //go right node -recursion
        Stree[idx] = Stree[2*idx+1] + Stree[2*idx+2]; //building tree
    }

    int RangeSumQuery(int idx,int start,int end,int l,int r){
        // idx = idx in seg tree array i.e. Stree
        // start, end = target range of which range sum we want fixed in recursive calls
        // l,r = range of nodes in seg tree , changes in recursive calls
        if(r<start || end<l){
            return 0; //BASE CASE - when nothing is in range
        }
        if(l>=start && r<=end){
            return Stree[idx];// BASE CASE  -  when both l and r are inside range
        }
        int mid = (l+r)/2;
        //recursion calls to left and right nodes 
        return RangeSumQuery(2*idx+1,start,end,l,mid)+ RangeSumQuery(2*idx+2,start,end,mid+1,r);
    }
    void updateSumQuery(int idx,int val,int i,int l,int r){
        //idx = idx of nums at which needs to update value to val
        //i = idx of seg tree
        //l,r - range in segment tree nodes
        if(l==r){
            Stree[i] = val; 
            return;
        }
        int mid = (l+r)/2;
        if(idx<=mid){
            //go left
            updateSumQuery(idx,val,2*i+1,l,mid);
        }else{
            //go right
            updateSumQuery(idx,val,2*i+2,mid+1,r);
        }
        //update
        Stree[i] = Stree[2*i+1] + Stree[2*i+2];
    }

    public:
    SegTree(vector<int> & nums){
        n = nums.size();
        Stree.assign(4*n,0);
        // if(n>0) BuildTree(nums,0,0,n-1);
    }
    void updateQuery(int idx,int val){
        updateSumQuery(idx,val,0,0,n-1);
    }
    int getRangeSum(int start,int end){
        return RangeSumQuery(0,start,end,0,n-1);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        //CONCEPT - for every triplet x,y,z 
        // let keep y fix then number of triplet having y in middle = (no of common elem to left of idx of i in both array * number of elements common to right of idx of y in both array)
        //if we find number of common elements in left side of y then we can get number of uncommon element to the left and with that we can get number of common element to the right

        //for y idx = 1, 2, ... n-1 we need to find common elements in [0..0], [0..1], [0..2] and so on
        // this gives intuition of SEGMENT TREES CONCEPT to be used here


        // APPROACH - to get common in range ,first initialize seg tree of all node 0 ,then mark visited elements indexes (in nums2)as 1 in seg tree as we keep moving y (basically update segtree each time y moves) then calc 

        SegTree st(nums1);
        map<int,int> mp;
        for(int i  = 0;i<nums2.size();i++){
            mp[nums2[i]] = i;
        } 
        st.updateQuery(mp[nums1[0]],1);
        long long sum = 0;
        int n = nums1.size();
        for(int i = 1;i<n-1;i++){
            int idx = mp[nums1[i]]; //idx of elem in nums2
            int leftcomm = st.getRangeSum(0,idx);
            int leftuncomm = i - leftcomm;
            int rightelem = n-idx-1;
            int rightcomm = rightelem-leftuncomm;
            long long res = (long long)rightcomm*leftcomm;
            sum+=res;
            st.updateQuery(mp[nums1[i]],1);
        }
        return sum;

    }
};