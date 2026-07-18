class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        long long fac = n/2;
        if(n%2==0){
            return (long long ) s+ fac *m - (fac -1);
        }  
        return (long long) s+ fac *m-(fac-1);
    }
};