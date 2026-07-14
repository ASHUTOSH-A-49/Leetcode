class SegTree{
    int n;
    vector<int> Stree;
    void BuildTree(vector<int> & arr,int idx,int l,int r){
        if(l==r){
            //BASE CASE
            //store max but indexes only not values
            Stree[idx] = r;
            return;
        }
        int mid = (l+r)/2;
        BuildTree(arr,2*idx+1,l,mid); //go left node -recursion
        BuildTree(arr,2*idx+2,mid+1,r); //go right node -recursion
        //building tree
        if(arr[Stree[2*idx+1]] > arr[Stree[2*idx+2]]){
            Stree[idx] = Stree[2*idx+1];
        }else Stree[idx] = Stree[2*idx+2];
         
    }

    int RangeMaxIDXQuery(int idx, int start, int end, int l, int r, vector<int> & arr) { 
        if (r < start || end < l) { 
            return -1; 
        } 
        if (l >= start && r <= end) { 
            return Stree[idx];
        } 
        int mid = (l + r) / 2; 
        int left = RangeMaxIDXQuery(2 * idx + 1, start, end, l, mid, arr);
        int right = RangeMaxIDXQuery(2 * idx + 2, start, end, mid + 1, r, arr);

        if (left == -1) return right;
        if (right == -1) return left;

        return (arr[left] >= arr[right]) ? left : right;
    } 

    public:
    SegTree(vector<int> & nums){
        n = nums.size();
        Stree.assign(4*n,0);
        if(n>0) BuildTree(nums,0,0,n-1);
    }
    int getLeftMostBS(int start, int end, int l, int r, int target, vector<int> & arr) {
        int low = start,high= end,ans = -1;
        while(low<=high){
            int mid = low+ (high-low)/2;
            int idx = RangeMaxIDXQuery(0,low,mid,0,n-1,arr);
            if(idx!=-1 && arr[idx]>target){
                ans = idx;
                high = mid-1;
            }else low = mid+1;
        }
        return ans;

    }
    int query(int start,int end,int target,vector<int> & arr){
        // a and b are alice and bob indexes
        return getLeftMostBS(start,end,0,n-1,target,arr);
    }
};

class Solution {
public:
//approach -  RMIQ + BS
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        SegTree st(heights);
        vector<int> ans;
        int n = heights.size();
        for(vector<int> q:queries){
            int a = q[0],b = q[1];
            if (a > b) swap(a, b); 
            if (a == b || heights[a] < heights[b]) { 
                //case I and edge case handled here only
                ans.push_back(b); 
                continue; 
            }
            //when a<b, and heights[a] > heights[b] ... use seg treee
            int idx = st.query(b+1,n-1,heights[a],heights);
            ans.push_back(idx);
        }
        return ans;
    }
};