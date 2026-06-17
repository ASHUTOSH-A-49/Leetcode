class Solution {
public:
    char kthCharacter(int k) {
        //smol constraints so jus simulate
        string s = "a";
        while(s.size()<k){
            string gen = "";
            for(char c:s){
                if(c=='z') gen+='a';
                else gen+=c+1;
            }
            s+=gen;
        }
        return s[k-1];
    }
};