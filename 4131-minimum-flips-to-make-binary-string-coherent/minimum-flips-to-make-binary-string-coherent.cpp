class Solution {
public:
    int minFlips(string s) {
        int cnt1 = 0,cnt0 = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]=='0') cnt0++;
            else cnt1++;
        }
        int ans;
        if(cnt1<=0 || cnt0==0) ans =  0;
        if(cnt1==2){
            if(s[0]=='1' && s[n-1]=='1') ans =  0;
            else
            ans =  1;
        }
        if(cnt1>2){
            if(s[0]=='1' && s[n-1]=='1'){
                if((cnt1-2)>=cnt0){
                    ans =  cnt0;
                }else{
                    ans =  cnt1-2;
                }
            }
            else{
                if(cnt1>cnt0){
                    ans =  cnt0;
                }
                if(cnt1<=cnt0){
                    ans =  cnt1-1;
                }
            }
        }
        return ans;
    }
};