class Solution {
public:
    int minChanges(string s) {
        int change = 0,cnt = 1;
        int i = 0;
        int n = s.size();
        while(i<n-1){
            while(i<n-1 && s[i]==s[i+1]) {
                cnt++;
                i++;
            }
            if(cnt&1) {
                if(i<n-1){
                    int prev = s[i]-'0';
                    s[i+1] = s[i];
                }
                change++;
                i++;
            }
            cnt = 1;
            i++;
        }
        return change;
    }
};