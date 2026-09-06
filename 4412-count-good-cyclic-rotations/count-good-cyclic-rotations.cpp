class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0,sum = 0;
        vector<long long> pre(n+1,0);
        for(int i = 0;i<n;i++) {
            pre[i+1] = pre[i]+nums[i];
        }
        for(int i =0;i<n;i++){
            int l1 = i,l2 = (i+n/2-1)%n;
            int r1 = (l2+1)%n,r2 = (r1+n/2-1)%n;
            long long left = (l2>=l1)? (pre[l2+1]-pre[l1]) : pre[n]-pre[l1] + pre[l2+1];
            long long right = (r2>=r1)? pre[r2+1]-pre[r1] : pre[n]-pre[r1] + pre[r2+1];
            if(left>right) cnt++;        
        }
        return cnt;
    }
};