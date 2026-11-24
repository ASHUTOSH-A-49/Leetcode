class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 1;
        for(int i = 0;i<n;i++){
            int l = 1,g;
            long long prod = 1;
            for(int j = i;j<n;j++){
                prod = prod*nums[j];
                cout<<prod<<endl;
                l = lcm(l,nums[j]);
                if(j==i) {
                    g = nums[i];
                }
                if(j!=i) g = gcd(g,nums[j]);
                
                // cout<<l<<" "<<g<<endl;
                if(l*g==prod){
                    maxlen = max(maxlen,j-i+1);
                }
                if(prod>l*g) break;
            }
            
        }
        return maxlen;
    }
};