class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1,n = nums.size();
        int cnt = 2,mono = 0;
        vector<int> scale(n-1);
        for(int i = 0;i<n-1;i++){
            int diff = nums[i+1]-nums[i];
            if(diff>0) scale[i] = 1;
            else if(diff<0) scale[i] = -1;
            else scale[i] = 0;
        }
        bool nonzero = false;
        for(int i:scale){
            if(i!=0){
                nonzero = true;
                break;
            }
        }
        if(!nonzero) return ans;
        for(int i = 0;i<n-2;i++){
            if(scale[i]!=0 && scale[i+1]!=0 && scale[i]==scale[i+1]){
                cnt++;
            }else cnt = 2;
            ans = max(cnt,ans);
        }
        ans = max(cnt,ans);
        return ans;
    }
};