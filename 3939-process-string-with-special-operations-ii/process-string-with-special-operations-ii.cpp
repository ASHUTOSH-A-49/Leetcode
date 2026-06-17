class Solution {
public:
    char processStr(string s, long long k) {
        long long int L = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]=='*'){if(L>0) L--;} 
            else if(s[i]=='#') L = L*2;
            else if(s[i]=='%') L = L;
            else L++;

        }
        if(k>=L) return '.';
        for(int i = n-1;i>=0;i--){
            if(s[i]=='*')L++;
            else if(s[i]=='%') k = L-k-1;
            else if(s[i]=='#'){
                L/=2;
                if(k>=L) k = k-L;
            }
            else {
                L--;
                if(L==k) return s[i];
            }
            
        }
        return '.';
    }
};