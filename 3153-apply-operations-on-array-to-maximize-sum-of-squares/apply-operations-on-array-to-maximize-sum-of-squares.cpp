class Solution {
public:
int MOD = 1e9+7;
    void intoBits(int n,vector<int> & bits){
        string s = "";
        while(n>0){
            int d = n%2;
            s+=(d==1) ? '1' : '0';
            n/=2;
        }
        for(int i = 0;i<s.size();i++){
            int b = s[i]-'0';
            bits[i]+=(b==1) ? 1:0;
        }
        // cout<<s<<endl;
    }

    int maxSum(vector<int>& nums, int l) {
        vector<int> bits(32,0);
        for(int i:nums){ //----------O(n*(31+log2(n)))
            intoBits(i,bits);
        }
        // for(int i:bits){
        //     cout<<i<<' ';
        // }
        int ans = 0;
        int i = 31;
        while(i>=0 && l>0){
            while(i>=0 && bits[i]==0) i--;
            if(i<0) break;
            if(l<=0) break;
            int mini = 1000001;
            for(int j = i;j>=0;j--){
                mini = min(mini,bits[j]);
            }
            if(mini==0){
                //take 1 from wherever possible and update bits
                long long num=0;
                long long k=1;
                if(bits[0]>0){
                    num=(num+k)%MOD;
                    bits[0]--;
                }
                k=(k*2)%MOD;
                for(int j=1;j<=i;j++){
                    if(bits[j]>0){
                        num=(num+k)%MOD;
                        bits[j]--;
                    }
                    k=(k*2)%MOD;
                }
                long long sq=(num*num)%MOD;
                ans=(ans+sq)%MOD;
                l--;
            }else{
                //take min from every element from j = i to j = 0 and update bits
                long long k = 1;
                long long num = 0;
                int mini1 = min(mini,l);
                for (int j = 0; j <= i; j++) {
                    bits[j] -= mini1;
                    if (mini1 > 0) {
                        num = (num + k) % MOD;
                    }
                    k = (k * 2) % MOD; 
                }
                long long sq = (num*num)%MOD;
                long long total_sq = (sq * mini1) % MOD;
                ans = (ans+total_sq)%MOD;
                l-=mini1;
            }
        }
        return ans;
    }
};