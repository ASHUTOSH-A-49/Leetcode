class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        vector<double> avg(n-1);
        vector<int> psum(n);
        int sum = 0;
        for(int i = n-1;i>=0;i--){
            psum[i] = sum;
            sum+=nums[i];
        }
        for(int i = n-1;i>0;i--){
            if(i==n-1) avg[i-1] = nums[n-1];
            else{
                avg[i-1] = double(psum[i-1])/(n-i);
            }
        }
        int cnt = 0;
        for(int i = 0;i<n-1;i++){
            cout<<avg[i]<<endl;
            if(nums[i]>avg[i])cnt++;
        }
        return cnt;
    }
};