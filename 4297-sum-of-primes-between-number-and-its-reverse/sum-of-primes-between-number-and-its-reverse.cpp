class Solution {
public:
    vector<int> primes = vector<int>(1001,1);
    
    void fillPrimes(){
        primes[0] = primes[1] = 0;
        for(int i = 2;i*i<=1000;i++){
            if(primes[i]==1){
                for(int j = i*i;j<=1000;j+=i){
                    primes[j] = 0;
                }
            }
        }
    }

    int revdig(int n){
        int r = 0;
        while(n>0){
            int dig = n%10;
            n = n/10;
            r= r*10 + dig;
        }
        return r;
    }
    int sumOfPrimesInRange(int n) {
        fillPrimes();
        int r = revdig(n);
        int mini = min(r,n);
        int maxi = max(r,n);
        // cout<<mini<<" "<<maxi<<endl;
        int sum = 0;
        for(int i = mini;i<=maxi;i++){
            if(primes[i]==1) sum+=i;
            // cout<<i<<endl;
        }
        return sum;
    }
};