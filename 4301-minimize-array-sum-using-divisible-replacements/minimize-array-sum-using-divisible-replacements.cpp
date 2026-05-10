class Solution {
public:
    vector<int> sieve;
    void primesieve(){
        
        int n = 1e5;
        sieve.assign(n + 1, 1);
        sieve[0] = sieve[1] = 0;
        for(int i = 2;i*i<=n;i++){
            if(sieve[i]==1){
                for(int j = i*i;j<=n;j+=i){
                    sieve[j] = 0;
                }
            }
        }
    }
    long long minArraySum(vector<int>& nums) {
        primesieve();
        sort(nums.begin(),nums.end(),greater<int>());
        if(nums[nums.size()-1]==1){
            return nums.size();
        }
        for(int i = 0;i<nums.size();i++){
            if(sieve[nums[i]]==1){
                if(nums[nums.size()-1]==1) nums[i] = 1;
            }
            else{
               for(int j = nums.size()-1;j>i;j--){
                
                if(nums[j]>(nums[i]/2)) break;
                if(nums[i]%nums[j]==0){
                   nums[i] = nums[j];
                break; 
                } 
            } 
            }
            
        }
        long long sum = 0;
        for(int i:nums) cout<<i<<" ";
        for(int i:nums) sum+=i;
        return sum;
        
    }
};