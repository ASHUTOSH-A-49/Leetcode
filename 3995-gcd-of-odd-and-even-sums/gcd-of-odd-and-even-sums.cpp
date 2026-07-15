class Solution {
public:
//approach -2: MATH AP formula
    int gcdOfOddEvenSums(int n) {
        int sumo,sume;
        int le = 2+(n-1)*2;
        int lo = 1+(n-1)*2;
        sume = n * (2+le)/2;
        sumo = n * (1+lo)/2;
        return gcd(sumo,sume);
    }
};