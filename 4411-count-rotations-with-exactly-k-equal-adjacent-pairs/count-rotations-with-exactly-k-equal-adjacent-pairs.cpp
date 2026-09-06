class Solution {
public:
    int getsc(string & s){
        int n = s.size();
        int sc = 0;
        for(int i = 0;i<n-1;i++){
            if(s[i]==s[i+1]) sc++;
        }
        return sc;
    }
    int countRotations(string s, int k) {
        int n = s.size();
        int cnt = 0;
        if(getsc(s)==k) cnt++;
        for(int i = 1;i<n;i++){
            char c = s[0];
            s.erase(s.begin());
            s.push_back(c);
            if(getsc(s)==k) cnt++;
            
        }
        return cnt;
    }
};