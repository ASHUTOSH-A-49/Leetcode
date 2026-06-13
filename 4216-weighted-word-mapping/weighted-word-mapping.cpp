class Solution {
public:
    int getWeight(vector<int> weights,string w){
        int n = w.size(),sum = 0;
        for(int i = 0;i<n;i++){
            sum+=weights[(w[i]-'a')];
        }
        return sum;
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string w:words){
            int sc = getWeight(weights,w) % 26;
            ans+='z'-sc;
        }
        return ans;
    }
};