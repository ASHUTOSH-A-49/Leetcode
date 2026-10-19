class Solution {
public:
    string getLCS(string & text1,string& text2){
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        //babcktracking to get lcs string
        string lcs_str = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                lcs_str.push_back(text1[i - 1]);
                i--;
                j--;
            } 
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(lcs_str.begin(), lcs_str.end());
        return lcs_str;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string lcsstr = getLCS(str1,str2);
        cout<<lcsstr<<endl;
        int m = str1.size(),n = str2.size(),s = lcsstr.size();
        int i = 0,j = 0,k = 0;
        string ans = "";
        while(k<s){
            while(i<m && str1[i]!=lcsstr[k]) {
                ans+=str1[i];
                i++;
            }
            while(j<n && str2[j]!=lcsstr[k]) {
                ans+=str2[j];
                j++;
            }
            ans+=lcsstr[k];
            k++;
            i++;
            j++;
            cout<<ans<<endl;
        }
        while(i<m){
            ans+=str1[i];
            i++;
        }
        while(j<n){
            ans+=str2[j];
            j++;
        }
        return ans;
    }
};