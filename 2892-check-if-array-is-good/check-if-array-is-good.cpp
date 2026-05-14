class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        bool check  = true;
        vector<int> freq(n,0);
        for(int i = 0;i<n;i++){
            if(nums[i]>=n){
                check  = false;
                // cout<<"greater break "<<i<<" "<<nums[i]<<endl;
                break;
            }else{
                // cout<<"enter to freq"<<endl;
                    freq[nums[i]]++;
                
            }
        }

        // for(int i:freq) cout<<i<<" ";
        // cout<<endl;
        for(int i = 1;i<n-1;i++){
            if(freq[i]!=1) {
                check = false;
                // cout<<"freq break"<<i<<" "<<freq[i]<<endl;
                break;
            }
        }
        if(freq[n-1]!=2){
            check = false;
            // cout<<"end freq break"<<endl;
        }
        return check;
    }
};