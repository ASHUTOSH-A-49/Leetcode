class Solution {
public:
    int MOD = 1e9 + 7;
    long long power(long long x,long long y){
        long long res = 1;
        x = x%MOD;
        while(y>0){
            if(y&1) res = (res*x) %MOD;
            y = y>>1;
            x = (x*x) % MOD;
        }
        return res;
        
        
    }
    int decode(long long num){
        int w = num%10;
        string str= to_string(num/10);
        
        long long x = 0,y = 0;
        for(int i = 0;i<str.size();i++){
            if(str[i]=='.') continue;
            if(w>0){
                x = x*10 + (str[i]-'0');
                w--;
            }else{
                y = y*10 + (str[i]-'0');
            }
        }
        
        return power(x,y);
    }
    int sumDecoded(vector<long long>& nums) {
        int sum = 0;
        for(long long i:nums){
            long long res = decode(i);
            sum = (sum+res)%MOD;
        }
        return sum;
    }
};