class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,endidx=-1,maxsiz=0,prev=-1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        while(r<n){
            if(r==0) {
                prev=nums[r];
                r++;
            }else{
                if(nums[r]==prev+1){
                    prev=nums[r];
                    r++;
                }else{
                    break;
                }
            }
            maxsiz=max(maxsiz,r-l+1);
            
        }
        endidx=r-1;
        int sum=0;
        for(int i=0;i<=endidx;i++){
            sum+=nums[i];
        }
        int next=sum;
        while(mp.count(next)!=0){
            next++;
        }
        return next;
    }
};