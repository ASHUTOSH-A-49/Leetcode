class Solution {
public:
    bool checkString(string s) {
        bool checkb = false;
        for(char c:s){
            if(c=='b') {
                checkb = true;
            }else{
                if(checkb) return false;
            }
        }
        return true;
    }
};