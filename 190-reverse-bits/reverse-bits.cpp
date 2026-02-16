class Solution {
public:
    string getrevbin(int n){
        string s = "";
        while(n>0){
            int d = n%2;
            n/=2;
            s+=to_string(d);
        }
        if(s.size()<32){
            int diff = 32-s.size();
            for(int i = 0;i<diff;i++){
                s+=to_string(0);
            }
        }
        string ans = "";
        for(int i = 31;i>=0;i--){
            ans+=s[i];
        }
        return ans;
    }
    int revint(string s){
        int k = 0,i = 0;
        for(char c:s){
            if(c=='1'){
                k+=1<<i;
            }
            i++;
        }
        return k;
    }
    int reverseBits(int n) {
        // cout<<getrevbin(n);
        return revint(getrevbin(n));
        // return n;
    }
};