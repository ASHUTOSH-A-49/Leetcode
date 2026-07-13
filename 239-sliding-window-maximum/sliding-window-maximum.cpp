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
        Stree[idx] = max(Stree[2*idx+1] , Stree[2*idx+2]); //building tree
    }

    int RangeMaxQuery(int idx,int start,int end,int l,int r){
        // idx = idx in seg tree array i.e. Stree
        // start, end = target range of which range max we want fixed in recursive calls
        // l,r = range of nodes in seg tree , changes in recursive calls
        if(r<start || end<l){
            return INT_MIN; //BASE CASE - when nothing is in range
        }
        if(l>=start && r<=end){
            return Stree[idx];// BASE CASE  -  when both l and r are inside range
        }

        int mid = (l+r)/2;
        //recursion calls to left and right nodes 
        return max(RangeMaxQuery(2*idx+1,start,end,l,mid), RangeMaxQuery(2*idx+2,start,end,mid+1,r));
    }

    public:
    SegTree(vector<int> & nums){
        n = nums.size();
        Stree.assign(4*n,INT_MIN);
        if(n>0) BuildTree(nums,0,0,n-1);
    }
    int getRangeMax(int start,int end){
        return RangeMaxQuery(0,start,end,0,n-1);
    }
};


class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //approach -2: use Segment Trees
        SegTree st(nums);
        vector<int> ans;
        int n = nums.size();
        int l = 0,r = k-1;
        while(r<n){
            ans.push_back(st.getRangeMax(l,r));
            l++;r++;
        }
        return ans;
        
    }
};