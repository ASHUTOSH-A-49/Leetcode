class Solution {
public:
    int minOperations(string s) {
        int minidx = -1,maxidx = -1;
        char minch = 'z'+1,maxch = 'a'-1;
        if(s.size()==1) return 0;
        bool isSort= true;
        int n = s.size();
        for(int i = 0;i<n-1;i++){
            if(s[i]>s[i+1]){
                isSort = false;
                break;
            }
        }
        if(isSort) return 0;
        for(int i = 0;i<n;i++){
            char c = s[i];
            if(c<minch) {
                minch = c;
                minidx = i;
            }
            if(c>=maxch) {
                maxch = c;
                maxidx = i;
            }
        }
        cout<<minidx<<" "<<maxidx;
        if(minidx==1 && maxidx==0 && s.size()==2){
            return -1;
        }
        if(minidx==0 || maxidx==n-1) return 1;
        if(minidx==n-1 && maxidx==0) return 3;
        return 2;
    }
};