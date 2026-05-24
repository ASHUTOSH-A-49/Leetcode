class Solution {
public:
    int passwordStrength(string password) {
        vector<int> freq(256,0);
        for(char c:password){
            freq[c]++;
        }
        int pnt = 0;
        for(int i = 0;i<256;i++){
            if(freq[i]>0){
                if(i==33 || i==35 || i==36 || i==64) pnt+=5;
                else if(i>=65 && i<=90) pnt+=2;
                else if(i>=97 && i<=122) pnt+=1;
                else if(i>=48 && i<=57) pnt+=3;
            }
            
        }
        return pnt;
    }
};