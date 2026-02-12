class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxlen = 0;
        for(int i = 0;i<n;i++){
            vector<int> hash(26,0);
            for(int j = i;j<n;j++){
                hash[s[j]-'a']++;
                int cnt = 0;bool flag = true;
                for(int k = 0;k<26;k++){
                    if(hash[k]>0){
                        if(cnt==0) cnt = hash[k];
                        else {
                            if(hash[k]!=cnt) {
                                flag = false;
                                break;
                            }
                        }
                    }
                }
                if(flag) maxlen = max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};