class Solution {
public:

    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int cnt = 0;
        int push = 0;
        for(int i:freq){
            if(i==0) break;
            if(cnt<8) push+= i;
            else if(cnt>=8 && cnt<16) push+=i*2;
            else if(cnt>=16 && cnt<24) push+=i*3;
            else push+=i*4;
            // cout<<push<<endl;
            cnt++;

        }
        return push;
    }
};