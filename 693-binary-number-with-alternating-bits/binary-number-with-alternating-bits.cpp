class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevbit = -1;
        while(n>0){
            int b = n%2;
            if(prevbit==-1) prevbit = b;
            else{
                if(prevbit==b){
                    return false;
                }else prevbit = b;
            }
            n/=2;
        }
        return true;
    }
};