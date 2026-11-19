class Solution {
public:
    int minimizeSum(vector<int>& v) {
        int n = v.size();
        if(n<=3) return 0;
        sort(v.begin(),v.end());
        int ans1,ans2,ans3;
        ans1=v[n-1]-v[2];
        ans2=v[n-3]-v[0];
        ans3 = v[n-2]-v[1];
        return min(ans1,min(ans2,ans3));

        
    }
};