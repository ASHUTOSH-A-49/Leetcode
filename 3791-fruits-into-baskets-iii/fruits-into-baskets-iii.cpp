class SegTree {
    int n;
    vector<int> Stree;

    void BuildTree(vector<int> & arr, int idx, int l, int r) {
        if (l == r) {
            Stree[idx] = l;
            return;
        }
        int mid = (l + r) / 2;
        BuildTree(arr, 2 * idx + 1, l, mid);
        BuildTree(arr, 2 * idx + 2, mid + 1, r);
        
        if (arr[Stree[2 * idx + 1]] >= arr[Stree[2 * idx + 2]]) {
            Stree[idx] = Stree[2 * idx + 1];
        } else {
            Stree[idx] = Stree[2 * idx + 2];
        }
    }

    void UpdateTree(int idx, int l, int r, int target_idx, vector<int> & arr) {
        if (l == r) return;
        int mid = (l + r) / 2;
        if (target_idx <= mid) {
            UpdateTree(2 * idx + 1, l, mid, target_idx, arr);
        } else {
            UpdateTree(2 * idx + 2, mid + 1, r, target_idx, arr);
        }
        if (arr[Stree[2 * idx + 1]] >= arr[Stree[2 * idx + 2]]) {
            Stree[idx] = Stree[2 * idx + 1];
        } else {
            Stree[idx] = Stree[2 * idx + 2];
        }
    }

    int FindLeftmost(int idx, int l, int r, int target, vector<int> & arr) {
        if (arr[Stree[idx]] < target) return -1;
        if (l == r) return l;

        int mid = (l + r) / 2;
        int left_res = FindLeftmost(2 * idx + 1, l, mid, target, arr);
        if (left_res != -1) return left_res;
        
        return FindLeftmost(2 * idx + 2, mid + 1, r, target, arr);
    }

public:
    SegTree(vector<int> & nums) {
        n = nums.size();
        Stree.assign(4 * n, 0);
        if (n > 0) BuildTree(nums, 0, 0, n - 1);
    }

    int queryAndMark(int target, vector<int> & arr) {
        int idx = FindLeftmost(0, 0, n - 1, target, arr);
        if (idx != -1) {
            arr[idx] = -1;
            UpdateTree(0, 0, n - 1, idx, arr);
        }
        return idx;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegTree st(baskets);
        int n = fruits.size();
        int cntplaced = 0;

        for (int f : fruits) {
            int idx = st.queryAndMark(f, baskets);
            if (idx != -1) {
                cntplaced++;
            }
        }
        return n - cntplaced;
    }
};