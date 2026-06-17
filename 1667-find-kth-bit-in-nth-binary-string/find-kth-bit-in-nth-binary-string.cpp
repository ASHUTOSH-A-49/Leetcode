class Solution {
public:
    string inversee(string s){
        for(int i = 0;i<s.size();i++){
            if(s[i]=='1') s[i] = '0';
            else s[i] = '1';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 0;i<n;i++){
            string inv = inversee(s);
            reverse(inv.begin(),inv.end());
            s = s+"1"+inv;
        }
        return s[k-1];
    }
};