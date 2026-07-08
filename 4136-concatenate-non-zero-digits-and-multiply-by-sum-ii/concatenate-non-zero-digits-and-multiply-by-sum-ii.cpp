int MOD = 1e9+7;

class SegTreeSum{
    int n;
    vector<int> Stree;
    void BuildTree(string & arr,int idx,int l,int r){
        if(l==r){
            //BASE CASE
            int d = arr[r]-'0';
            Stree[idx] = d;
            return;
        }
        int mid = (l+r)/2;
        BuildTree(arr,2*idx+1,l,mid); //go left node -recursion
        BuildTree(arr,2*idx+2,mid+1,r); //go right node -recursion
        Stree[idx] = (Stree[2*idx+1] + Stree[2*idx+2]) % MOD;  //building tree
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
                return (RangeSumQuery(2*idx+1,start,end,l,mid) + RangeSumQuery(2*idx+2,start,end,mid+1,r)) % MOD;

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
    SegTreeSum(string & s){
        n = s.size();
        Stree.assign(4*n,0);
        if(n>0) BuildTree(s,0,0,n-1);
    }
    void updateQuery(int idx,int val){
        updateSumQuery(idx,val,0,0,n-1);
    }
    int getRangeSum(int start,int end){
        return RangeSumQuery(0,start,end,0,n-1);
    }
};


class SegTreeDig{
    int n;
    vector<pair<int,int>> Stree;
    vector<int> power10;
    int getDig(int n){
        int d = 0;
        while(n>0){
            d++;
            n/=10;
        }
        return d;
    }
    void BuildTree(string & arr,int idx,int l,int r){
        if(l==r){
            //BASE CASE
            int d = arr[r]-'0';
            if(d==0){
                Stree[idx] = {d,0};
            }else Stree[idx] = {d,1};
            return;
        }
        int mid = (l+r)/2;
        BuildTree(arr,2*idx+1,l,mid); //go left node -recursion
        BuildTree(arr,2*idx+2,mid+1,r); //go right node -recursion
        int d = Stree[2*idx+2].second;
         int res = ((1LL * Stree[2*idx+1].first * power10[d]) % MOD + Stree[2*idx+2].first) % MOD;
        Stree[idx] = {res,Stree[2*idx+1].second+d}; //building tree
    }

    pair<int,int> RangeDigQuery(int idx,int start,int end,int l,int r){
        // idx = idx in seg tree array i.e. Stree
        // start, end = target range of which range sum we want fixed in recursive calls
        // l,r = range of nodes in seg tree , changes in recursive calls
        if(r<start || end<l){
            return {0,0}; //BASE CASE - when nothing is in range
        }
        if(l>=start && r<=end){
            return Stree[idx];// BASE CASE  -  when both l and r are inside range
        }
        int mid = (l+r)/2;
        //recursion calls to left and right nodes 
        auto left = RangeDigQuery(2*idx+1,start,end,l,mid);
        auto right = RangeDigQuery(2*idx+2,start,end,mid+1,r);
         int res = ((1LL * left.first * power10[right.second]) % MOD + right.first) % MOD;
        return {res,left.second+right.second};
    }
    // void updateSumQuery(int idx,int val,int i,int l,int r){
    //     //idx = idx of nums at which needs to update value to val
    //     //i = idx of seg tree
    //     //l,r - range in segment tree nodes
    //     if(l==r){
    //         Stree[i] = val; 
    //         return;
    //     }
    //     int mid = (l+r)/2;
    //     if(idx<=mid){
    //         //go left
    //         updateSumQuery(idx,val,2*i+1,l,mid);
    //     }else{
    //         //go right
    //         updateSumQuery(idx,val,2*i+2,mid+1,r);
    //     }
    //     //update
    //     Stree[i] = Stree[2*i+1] + Stree[2*i+2];
    // }

    public:
    SegTreeDig(string & s){
        n = s.size();
        Stree.assign(4*n,{0,0});
         power10.assign(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            power10[i] = (1LL * power10[i-1] * 10) % MOD;
        }
        if(n>0) BuildTree(s,0,0,n-1);
    }
    void updateQuery(int idx,int val){
        // updateSumQuery(idx,val,0,0,n-1);
    }
    int getRangeDig(int start,int end){
        auto p =  RangeDigQuery(0,start,end,0,n-1);
        return p.first;
    }
};

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        SegTreeSum STsum(s);
        SegTreeDig STdig(s);
        vector<int> ans;
        for(vector<int> q:queries){
            int sum = STsum.getRangeSum(q[0],q[1]);
            int dig = STdig.getRangeDig(q[0],q[1]);
            int res = (1LL * (sum % MOD) * (dig % MOD)) % MOD;
            ans.push_back(res);
        }
        return ans;
    }
};