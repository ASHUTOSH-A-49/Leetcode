class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq(128,0);
        int  n = word.size();
        for(int i = 0;i<n;i++){
            freq[word[i]]++;
        }
        int cnt = 0;
        for(int i = 0;i<91;i++){
            if(freq[i]>0){
                cout<<i<<endl;
                if(freq[i+32]>0) cnt++;
            }
        }
        return cnt;
    }
};