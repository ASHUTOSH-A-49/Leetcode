class Solution {
public:
    int getprod(int n){
        int prod = 1;
        while(n){
            int dig = n%10;
            prod = prod*dig;
            n/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while(getprod(n)%t !=0){
            getprod(n++);
        }
        return n;
    }
};