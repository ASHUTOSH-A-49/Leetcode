class Node{
    public:
    int pref,suff,maxval;
    char leftChar,rightChar;
    Node(int pref = 0, int suff = 0, int maxval = 0, char left = '#', char right = '#'){
        this->pref = pref;
        this->suff = suff;
        this->maxval = maxval;
        leftChar = left;
        rightChar = right;
    }
};


class SegTree{
    int n;
    vector<Node> Stree;
     Node merge(const Node& left, const Node& right, int leftLength, int rightLength) {
        Node root;
        root.maxval = max(left.maxval, right.maxval);
        root.pref = left.pref;
        root.suff = right.suff;
        root.leftChar = left.leftChar;
        root.rightChar = right.rightChar;

        if (left.rightChar == right.leftChar) {
            int sum = left.suff + right.pref;
            root.maxval = max(sum, root.maxval);
            if (left.pref == leftLength) {
                root.pref = leftLength + right.pref;
            }
            if (right.suff == rightLength) {
                root.suff = rightLength + left.suff;
            }
             root.maxval = max({root.maxval, root.pref, root.suff});
        }
        return root;
    }
    void BuildTree(string & arr, int idx, int l, int r) {
        if (l == r) {
            Stree[idx] = Node(1, 1, 1, arr[r], arr[r]);
            return;
        }
        int mid = (l + r) / 2;
        BuildTree(arr, 2 * idx + 1, l, mid); 
        BuildTree(arr, 2 * idx + 2, mid + 1, r); 
        Stree[idx] = merge(Stree[2 * idx + 1], Stree[2 * idx + 2],mid - l + 1, r - mid);
    }

    Node RangeMaxQuery(int idx,int start,int end,int l,int r){
        // idx = idx in seg tree array i.e. Stree
        // start, end = target range of which range max we want fixed in recursive calls
        // l,r = range of nodes in seg tree , changes in recursive calls
        if(r<start || end<l){
            return Node(0, 0, 0, '#', '#'); //BASE CASE - when nothing is in range
        }
        if(l>=start && r<=end){
            return Stree[idx];// BASE CASE  -  when both l and r are inside range
        }
        int mid = (l+r)/2;
        //recursion calls to left and right nodes 
        Node left = RangeMaxQuery(2*idx+1,start,end,l,mid);
        Node right = RangeMaxQuery(2*idx+2,start,end,mid+1,r);
        if (left.maxval == 0) return right;
        if (right.maxval == 0) return left; 
        int leftLen = min(mid, end) - max(l, start) + 1;
        int rightLen = min(r, end) - max(mid + 1, start) + 1;
        return merge(left, right,leftLen, rightLen);
    }
    void updateMaxQuery(int idx,char val,int i,int l,int r){
        //idx = idx of nums at which needs to update value to val
        //i = idx of seg tree
        //l,r - range in segment tree nodes
        if(l==r){
            Stree[i] = Node(1, 1, 1, val, val);
            return;
        }
        int mid = (l+r)/2;
        if(idx<=mid){
            //go left
            updateMaxQuery(idx,val,2*i+1,l,mid);
        }else{
            //go right
            updateMaxQuery(idx,val,2*i+2,mid+1,r);
        }
        //update
        Stree[i] = merge(Stree[2 * i + 1], Stree[2 * i + 2],mid - l + 1, r - mid);
    }

    public:
    SegTree(string & s){
        n = s.size();
        Stree.assign(4 * n, Node());
        if (n>0) BuildTree(s, 0, 0,n-1);
    }
    void updateQuery(int idx,int val){
       updateMaxQuery(idx, val, 0, 0, n - 1);
    }
    int getRangeMax(int start,int end){
        return RangeMaxQuery(0, start, end, 0, n - 1).maxval;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegTree st(s);
        int n = s.size();
        int k = queryIndices.size();
        vector<int> ans;
        for(int i = 0;i<k;i++){
            st.updateQuery(queryIndices[i],queryCharacters[i]);
            int res = st.getRangeMax(0,n-1);
            ans.push_back(res);
        }
        return ans;
    }
};