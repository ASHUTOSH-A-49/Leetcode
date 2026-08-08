class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> RHSmatch(m+1,0);
        int cnt = 0;
        int j = word2.size()-1;
        for(int i = m-1;i>=0;i--){
            if(j>=0 && word1[i]==word2[j]){
                j--;
                cnt++;
            }
            RHSmatch[i] = cnt;
        }

        bool convert = true;
        j = 0;
        
        vector<int> ans;
        for(int i = 0;i<m;i++){
            if(j>=n) break;
            if(word1[i]==word2[j]) {
                ans.push_back(i);
                j++;
            }else{
                if(convert && RHSmatch[i+1]>=n-j-1){
                    convert = false;  
                    ans.push_back(i);
                    j++; 
                }
            }    
        }
        // for(int i:ans) cout<<i<<" ";
        vector<int> dummy;
        return (j==n)?ans:dummy;
    }
};