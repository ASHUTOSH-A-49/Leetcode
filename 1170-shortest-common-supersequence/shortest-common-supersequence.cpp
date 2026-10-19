class Solution {
public:
//APPROACH 2 - direct from backtracking on the fly
    string getSCS(string & text1, string & text2){
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
        string scs_str = "";
        int i = m, j = n;
        
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                scs_str.push_back(text1[i - 1]);
                i--;
                j--;
            } 
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs_str.push_back(text1[i-1]);
                i--;
            } else {
                scs_str.push_back(text2[j-1]);
                j--;
            }
        }
        while(i>0){
            scs_str.push_back(text1[i-1]);
            i--;
        }
        while(j>0){
            scs_str.push_back(text2[j-1]);
            j--;
        }
        // The string was collected backwards, so reverse it to get the correct chronological order
        reverse(scs_str.begin(), scs_str.end());
        return scs_str;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        // Step 1: Extract the LCS string using the helper function
        string scsstr = getSCS(str1,str2);
        return scsstr;
    }
};