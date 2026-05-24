class Solution {
public:
    bool cycsort(vector<int> & nums){
        int n = nums.size();
        if(n<=2) return true;
        int d = 0,u = 0;
        for(int i = 0;i<n;i++){
            int cur = nums[i];
            int nex = nums[(i+1)%n];
            if(cur>nex) d++;
            if(cur<nex) u++;
        }
        return (d<=1 || u<=1);
    }
    bool asc(vector<int> & nums){
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        if(cycsort(nums)){
            if(asc(nums))return 0;
            int n = nums.size();
            // if(n<=2) return true;
            int d = 0,u = 0;
            for(int i = 0;i<n;i++){
                int cur = nums[i];
                int nex = nums[(i+1)%n];
                if(cur>nex) d++;
                if(cur<nex) u++;
            }
            int minops = 100000000;
            if(d<=1){
                int minval = nums[0];
                int mini = 0;
                for(int i = 1;i<n;i++){
                    if(nums[i]<minval){
                        minval = nums[i];
                        mini = i;
                    }
                }
                minops = min(minops,mini); //lef
                minops = min(minops, (n - mini) + 2); //rev-lr-rev
            }
            if(u<=1){
                //revrot
                vector<int> revnum = nums;
                reverse(revnum.begin(),revnum.end());
                int revs = 1;
                if(asc(revnum)){
                    minops = min(minops,revs);
                }
                else{
                    int minval = revnum[0];
                    int mini = 0;
                    for(int i = 1;i<n;i++){
                    if(revnum[i]<minval){
                        minval = revnum[i];
                        mini = i;
                    }
                    }
                    minops = min(minops,revs+mini);
                }
                //rotrev
                int maxval = nums[0];
                int maxi = 0;
                for(int i = 1;i<n;i++){
                    if(nums[i]>maxval){
                        maxval = nums[i];
                        maxi = i;
                    }
                }
                minops = min(minops,maxi+1);
            }
            return minops;
        }
        return -1;
    }
};