class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minsum = 0;
        for(int i = 0;i<n;i++){
            int subsum = 0;
            for(int j = i;j<n;j++){
                subsum+=nums[j];
                int siz = j-i+1;
                if(siz>=l && siz<=r){
                    if(subsum>0){
                        if(minsum==0) minsum = subsum;
                        else minsum = min(minsum,subsum);
                    }
                }
            }
        }
        return (minsum==0)?-1:minsum;
    }
};