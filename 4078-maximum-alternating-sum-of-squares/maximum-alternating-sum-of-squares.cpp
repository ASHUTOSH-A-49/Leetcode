class Solution {
public:
// O(nlogn) approach
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end(), greater<int>());
        if(n&1){
            for(int i=0;i<=n/2;i++){
                ans+= nums[i]*nums[i];
            }
            for(int i=n/2+1;i<n;i++){
                ans-=nums[i]*nums[i];
            }
        }else{
            for(int i=0;i<n/2;i++){
                ans+= nums[i]*nums[i];
            }
            for(int i=n/2;i<n;i++){
                ans-=nums[i]*nums[i];
            }
        }
        return ans;
    }
};