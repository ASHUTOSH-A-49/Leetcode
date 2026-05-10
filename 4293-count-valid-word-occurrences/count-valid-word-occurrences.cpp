class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        
        string str = "";
        for(string s:chunks){
            str+=s;
        }

        int n = str.size();
        unordered_map<string,int> valid;
        string curr = "";
        for(int i = 0;i<n;i++){
            if(str[i]>=97 && str[i]<=122){
                curr+=str[i];
            }else if(str[i]=='-'){
                if (i>0 && i<n-1 && (str[i-1]>=97 && str[i-1]<=122) && (str[i+1]>=97 && str[i+1]<=122)) {
                    curr += str[i];
                } else {
                    if (!curr.empty()) valid[curr]++;
                    curr = "";
                }
            }else{
                if(curr.size()>0) valid[curr]++;
                curr= "";
            }
        }
        if(curr.size()>0) valid[curr]++;
        curr = "";
    vector<int> ans;
        for(string q:queries){
         ans.push_back(valid[q]);
        }
        return ans;
    }
};