typedef long long ll;
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        long long MOD = 1e9+7;
        vector<int> arr(n);
        for(int i = 0;i<n;i++){
            if(nums[i]<a) arr[i] = -1;
            else if(nums[i]>b) arr[i] = 1;
            else arr[i] = 0;
        }
        int pos1 = 0;
        ll swaps = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]==-1){
                swaps+=(i-pos1);
                pos1++;
            }
        }
        int cnt1 = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]==0) swaps+=cnt1;
            else if(arr[i]==1) cnt1++;
        }
        return swaps%MOD;
        
    }
};