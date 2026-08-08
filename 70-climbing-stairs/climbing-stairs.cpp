class Solution {
public:

    int climbStairs(int n) {
        //TABULATION with space optimization
        if(n==1) return n;
        int next = 2,next2 = 1;
        for(int i = n-2;i>0;i--){
            int curr = next+next2;
            next2 = next;
            next = curr;
        }
        return next;
        
    }
};