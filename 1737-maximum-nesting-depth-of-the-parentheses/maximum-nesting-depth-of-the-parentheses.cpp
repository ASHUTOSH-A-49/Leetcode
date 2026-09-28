class Solution {
public:
    int maxDepth(string s) {
        int maxl =  0,cntl = 0;
        for(char c:s){
            if(c=='('){
                cntl++;
            }
            if(c==')'){
                cntl--;
            }
            maxl = max(maxl,cntl);
        }
        return maxl;
    }
};