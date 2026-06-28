class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        map<char,int> vals;
        vals['I'] = 1;
        vals['V'] = 5;
        vals['X'] = 10;
        vals['L'] = 50;
        vals['C'] = 100;
        vals['D'] = 500;
        vals['M'] = 1000;
        int n = s.size();
        
        for (int i = 0; i<n;i++) {
            if (i+1<n && vals[s[i]]<vals[s[i + 1]]) {
                num-=vals[s[i]];
            } else {
                num+=vals[s[i]];
            }
        }
        return num;
    }
};