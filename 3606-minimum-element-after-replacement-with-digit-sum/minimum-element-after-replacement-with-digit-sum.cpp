class Solution {
public:
int getSum(int a){
    int sum = 0;
    while(a>0){
        int dig = a%10;
        a/=10;
        sum+=dig;
    }
    return sum;
}
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int mini = 50;
        for(int i = 0;i<n;i++){
            int k = getSum(nums[i]);
            nums[i] = k;
            mini = min(mini,k);
        }
        return mini;
    }
};