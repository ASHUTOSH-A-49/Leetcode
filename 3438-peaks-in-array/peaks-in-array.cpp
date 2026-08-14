class SegTree{
    int n;
    vector<int> Stree;
    vector<int> peaks;
    vector<int> arr;
    
    void BuildTree(int idx,int l,int r){
        if(l==r){
            //BASE CASE
            Stree[idx] = peaks[r];
            return;
        }
        int mid = (l+r)/2;
        BuildTree(2*idx+1,l,mid); //go left node -recursion
        BuildTree(2*idx+2,mid+1,r); //go right node -recursion
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
    int isPeak(int idx){
        if(idx>0 && idx<n-1){
            if(arr[idx]> arr[idx-1] && arr[idx]>arr[idx+1]) return 1;
        }
        return 0;
    }

    public:
    SegTree(vector<int> & nums){
        n = nums.size();
        arr = nums;
        peaks.assign(n,0);
        for(int i = 1;i<n-1;i++) peaks[i] = isPeak(i);
        Stree.assign(4*n,0);
        if(n>0) BuildTree(0,0,n-1);
    }
    void updateQuery(int idx,int val){
        if(idx<0 || idx>=n) return;
        arr[idx] = val;
        for(int i = idx-1;i<=idx+1;i++){
            if(i>=0 && i<n){
                int pnext = isPeak(i);
                if(peaks[i]!=pnext){
                    peaks[i] = pnext;
                    updateSumQuery(i,pnext,0,0,n-1);
                }
            }
        }
        
    }
    int getRangeSum(int start,int end){
        if(start>=end-1) return 0;
        return RangeSumQuery(0,start+1,end-1,0,n-1);
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        SegTree st(nums);
        vector<int> ans;
        for(auto q:queries){
            int t = q[0];
            if(t==1){
                int l = q[1],r = q[2];
                ans.push_back(st.getRangeSum(l,r));
            }else{
                int idx = q[1],val = q[2];
                st.updateQuery(idx,val);
            }    
        }
        return ans;
    }
};