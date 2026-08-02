class Solution {
    int LB(vector<long long> & pre,long long target){
        int l = 0,r = pre.size()-1;
        int idx = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(pre[mid]<=target){
                idx = mid;
                l = mid+1;
            }else r = mid-1;
        }
        return idx;
    }
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> pre(n);
        pre[0]=  tasks[0];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1]+tasks[i];
        }
        int m = shifts.size();
        vector<int> ans(m);
        long long target = 0;

        for(int i = 0;i<m;i++){
            
            target+=shifts[i];
            int idx = LB(pre,target);
            if(idx==n-1) target = 0;
            ans[i] = n-(idx+1);
        }
        return ans;
        
    }
};