class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> lsum(n),rsum(n);
        int sum = 0;
        for(int i = 0;i<n;i++){
            lsum[i] = sum;
            sum+=nums[i];
        }
        sum = 0;
        for(int i =n-1;i>=0;i--){
            rsum[i] = sum;
            sum+=nums[i];
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            ans.push_back(abs(lsum[i]-rsum[i]));
        }
        return ans;
    }
};