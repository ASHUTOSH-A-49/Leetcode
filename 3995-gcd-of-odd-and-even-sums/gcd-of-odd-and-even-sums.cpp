class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumo = 0,sume = 0;
        int o = 1,e = 2;
        for(int i = 0;i<n;i++){
            sumo+=o;o+=2;
        }
        for(int i = 0;i<n;i++){
            sume+=o;e+=2;
        }
        return gcd(sumo,sume);
    }
};