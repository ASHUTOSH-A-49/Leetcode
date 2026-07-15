class Solution {
public:
//approach -3: MATH direct sequence formula
    int gcdOfOddEvenSums(int n) {
        return gcd(n*n,n*(n+1));
    }
};