class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int cnty = 0;
        string newst = "";
        int n = s.size();
        for(int i = 0;i<n;i++){
            char c = s[i];
            if(c==y){
                cnty++;
            }else{
                newst+=c;
            }
        }
        string newst2 = "";
        for(int i = 0;i<cnty;i++){
            newst2+=y;
        }
        newst = newst2+newst;
        return newst;
    }
};