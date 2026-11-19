class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<=3) return 0;
        vector<int> v1 = nums,v2 = nums,v3 = nums;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());
        int ans1,ans2,ans3;
        v1[0] = v1[2];v1[1] = v1[2];
        v2[n-1] = v2[n-3];v2[n-2] = v2[n-3];
        v3[n-1] = v3[n-2];v3[0] = v3[1];
        ans1=v1[n-1]-v1[0];
        ans2=v2[n-1]-v2[0];
        ans3 = v3[n-1]-v3[0];
        return min(ans1,min(ans2,ans3));

        
    }
};