class Solution {
public:
long long mo = 1e9 +7;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mo;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mo;
            base = (base * base) % mo;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = (n + 1) / 2;
        long long firstHalf = power(5, even);
        long long secondHalf = power(4, odd);
        
        return (firstHalf * secondHalf) % mo;
    }
};