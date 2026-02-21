class Solution {
public:
    int countSetBits(int k){
        int sb = 0;
        while(k>0){
            int bit = k%2;
            if(bit==1) sb++;
            k/=2;
        }
        return sb;
    }
    int countPrimeSetBits(int left, int right) {
        vector<int> primes31 = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
        int ans = 0;
        for(int i = left;i<=right;i++){
            int sb = countSetBits(i);
            cout<<sb<<endl;
            if(primes31[sb]) ans++;
        }
        return ans;
    }
};