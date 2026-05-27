class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<int,int>> freq(128,{0,-1});
        for(int i = 0;i<word.size();i++){
            if(word[i]<97){
                if(freq[word[i]].first==0){
                freq[word[i]].first++;
                freq[word[i]].second = i;
                }
            }else{
                freq[word[i]].first++;
                freq[word[i]].second = i;
            }
            
        }
        int cnt = 0;
        for(int i = 97;i<=122;i++){
            if(freq[i].first>0){
                if(freq[i].second<freq[i-32].second){
                    cout<<freq[i].second<<" "<<freq[i-32].second<<endl;
                    cnt++;
                } 
            }
        }
        return cnt;
    }
};