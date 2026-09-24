class Solution {
public:
int digsum(int n){
    int res = 0;
    while(n){
        int d = n%10;
        n/=10;
        res+=d;
    }
    return res;
}
    int smallestIndex(vector<int>& nums) {
        int ans  = -1;
        int n = nums.size();
        for(int i = n-1;i>=0;i--){
            if(digsum(nums[i])==i){
                ans = i;
            }
        }
        return ans;
    }
};