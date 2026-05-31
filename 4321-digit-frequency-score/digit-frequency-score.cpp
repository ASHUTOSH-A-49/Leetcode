class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10,0);
        int k = n;
        while(n>0){
            int d = n%10;
            freq[d]++;
            n = n/10;
        }
        int sum = 0;
        for(int i = 0;i<10;i++){
            sum+=i*freq[i];
        }
        return sum;
    }
};