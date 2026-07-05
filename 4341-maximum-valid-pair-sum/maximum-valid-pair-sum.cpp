class SegTree{
    int n;
    vector<int> Stree;
    void buildTree(vector<int> & arr,int idx,int l,int r){
        if(l==r){
            Stree[idx] = arr[r];
            return;
            
        }
        int mid = (l+r)/2;
        buildTree(arr,2*idx+1,l,mid);
        buildTree(arr,2*idx+2,mid+1,r);
        Stree[idx] = max(Stree[2*idx+1],Stree[2*idx+2]);  
    }

    int getMax(int idx,int strt,int end,int l,int r){
        if(r<strt || end<l){
            return INT_MIN;
        }
        if(l<=strt && end<=r){
            return Stree[idx];
        }
        int mid = (strt+end)/2;
        return max(getMax(2*idx+1,strt,mid,l,r),getMax(2*idx+2,mid+1,end,l,r));
    }
    public:
    SegTree(vector<int> & arr){
        n = arr.size();
        Stree.assign(4*n,0);
        if(n>0){
            buildTree(arr,0,0,n-1);
        }
        
        
    }
    int getMaxRange(int l,int r){
        return getMax(0,0,n-1,l,r);
    }
};


class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        SegTree st(nums);
        int n = nums.size();
        int maxans = INT_MIN;
        for(int i = 0;i<n-k;i++){
            int j = i+k;
            int lmax = nums[i];
            int rmax = st.getMaxRange(j,n-1);
            maxans = max(maxans,lmax+rmax);
        }
        return maxans;
        
    }
};