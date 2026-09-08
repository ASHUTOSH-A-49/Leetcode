class Solution {
public:
    int countCommas(int n) {
        int div = 1000;
        int cnt = 0;
        if(n>=div){
            cnt+=n-div+1;
            n/=div;
        }
        return cnt;
    }
};