class Solution {
public:
    int minimumPushes(string word) {
        int a= word.size();
        if(a<=8) return a;
        if(a>8 && a<=16) return 8+ 2*(a-8);
        if(a>16 && a<=24) return 24+ 3*(a-16);
        return 48+ 4*(a-24);
    }
};