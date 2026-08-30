class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx = -1,maxidx = -1,mini = 1e6,maxi = -1e6;
        for(int i =0;i<n;i++){
            int num = nums[i];
            if(num>maxi) {
                maxi = num,maxidx = i;
            }
            if(num<mini) {
                mini = num;
                minidx = i;
            }
        }
        int l ,r ,lr ;
        if(minidx<maxidx) {
            l = maxidx+1;
            r = n-minidx;
            lr = minidx+1 + n-maxidx;
            
        }else{
            l = minidx+1;
            r = n-maxidx;
            lr = maxidx+1 + n-minidx;

        }
        cout<<maxidx<<" "<<minidx<<endl;
        cout<<l<<endl<<r<<endl<<lr<<endl;
        return min({l,r,lr});

    }
};