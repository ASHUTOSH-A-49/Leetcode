class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256,0);
        for(int i = 0;i<s.size();i++){
            freq[s[i]]++;
        }

        vector<pair<int,int>> ans;
        for(int i = 0;i<256;i++){
            if(freq[i]>0){
                ans.push_back({freq[i],i});
            }
        }
        sort(ans.begin(),ans.end(),greater<pair<int, int>>());
        string ansstr = "";
        for(int i = 0;i<ans.size();i++){
            char ch = ans[i].second;
            for(int j = 0;j<ans[i].first;j++){
                ansstr+=ch;
            }
        }
        return ansstr;
    }
};