class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return 0;
        int maxlen = 0;
        for(int i = 0;i<n;i++){
            map<int,int> evenhash;
            map<int,int> oddhash;
            for(int j = i;j<n;j++){
                if(nums[j]%2==0) evenhash[nums[j]]++;
                else oddhash[nums[j]]++;
                if(evenhash.size()==oddhash.size()){
                    maxlen = max(maxlen,j-i+1);
                } 
            }
            
        }
        return maxlen;

    }
};