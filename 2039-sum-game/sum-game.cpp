class Solution {
public:
   bool sumGame(string num) {
        int n = num.size();

        int lsum = 0,rsum = 0,lq = 0,rq = 0;
        int mid = n/2;
        for(int i = 0;i<n;i++){
            char c = num[i];
            if(i<mid){
                (c=='?')? lq++:lsum+=(c-'0');
            }else{
                (c=='?')? rq++:rsum+=(c-'0');
            }
        }
        if((lq+rq)&1) return true;
        int left = 2*lsum + 9*lq;
        int right = 2*rsum+9*rq;
        //for bob to win left == right;
        return (!(left==right));
    }
};