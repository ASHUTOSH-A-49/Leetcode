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
        // for one side due to question marks : (x+9-x + y+9-y ) = 18 for 4 q mark om one side
        // i.e. one ques mark weights 18/4  = 4.5
        // therefore for one side sum = known sum (lsum or rsum) + 4.5 * no of ques 
        if((lq+rq)&1) return true;
        int left = lsum + 4.5*lq;
        int right = rsum+4.5*rq;
        //for bob to win left == right;
        return (!(left==right));
    }
};