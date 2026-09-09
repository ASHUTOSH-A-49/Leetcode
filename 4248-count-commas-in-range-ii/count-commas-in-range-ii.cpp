class Solution {
public:
    long long countCommas(long long n) {
        long long tot = 0;
        for(long long b = 1000;b<=n;b*=1000){
            tot+=(n-b+1);
        }
        return tot;
    }
};