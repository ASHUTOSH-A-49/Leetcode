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
        Stree[idx] = Stree[2*idx+1]+Stree[2*idx+2];  
    }

    int getSum(int idx,int strt,int end,int l,int r){
        if(r<strt || end<l){
            return 0;
        }
        if(l>=strt && r<=end){
            return Stree[idx];
        }
        int mid = (l+r)/2;
        return getSum(2*idx+1,strt,end,l,mid)+getSum(2*idx+2,strt,end,mid+1,r);
    }
    public:
    SegTree(vector<int> & arr){
        n = arr.size();
        Stree.assign(4*n,0);
        if(n>0){
            buildTree(arr,0,0,n-1);
        }
    }
    int getRangeSum(int start,int end){
        return getSum(0,start,end,0,n-1);
    }
};


class NumArray {
    SegTree* st;
public:
    
    NumArray(vector<int>& nums) {
        st = new SegTree(nums);
    }
    
    int sumRange(int left, int right) {
        return st->getRangeSum(left,right);
    }
    ~NumArray() {
        delete st;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */