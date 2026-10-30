class Solution {
public:
//TABULATION APPROACH with SPACE OPTIMIZATION
    int minDistance(string word1, string word2) {
        int m = word1.size(),n = word2.size();
        vector<int> prev(n+1),curr(n+1);
        prev[n] = 0;curr[n] = 0;
        for(int j = 0;j<=n;j++){
            prev[j] = n-j;
        }
        for(int i = m-1;i>=0;i--){
            curr[n] = m-i;
            for(int j = n-1;j>=0;j--){
                int repl = ((word1[i]==word2[j])?0:1) + prev[j+1];
                int ins = 1 + curr[j+1];
                int del = 1+prev[j];
                curr[j] = min({repl,ins,del});
            }
            prev = curr;
        }
        return prev[0];
    }
};