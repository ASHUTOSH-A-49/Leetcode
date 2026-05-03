class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = i+1;j<n;j++){
                
                if(nums[i]%2 != nums[j]%2){
                    // cout<<i<<" "<<j<<endl;
                    cnt++;
                }
                
                
            }
            ans[i] = cnt;
        }
        return ans;
    }
};