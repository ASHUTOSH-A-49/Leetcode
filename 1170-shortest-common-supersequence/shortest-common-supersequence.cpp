class Solution {
public:
    // Helper function to find and return the actual Longest Common Subsequence string
    string getLCS(string & text1, string & text2){
        int m = text1.size(), n = text2.size();
        
        // 1. Initialize a 2D DP table with 0s. 
        // dp[i][j] stores the length of LCS for prefixes text1[0...i-1] and text2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // 2. Build the DP table bottom-up
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match, add 1 to the result of the diagonal top-left subproblem
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                // If they don't match, take the maximum from the top cell or left cell
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // 3. Backtracking step to construct the actual LCS string from the DP table
        string lcs_str = "";
        int i = m, j = n; // Start from the bottom-right corner
        
        while (i > 0 && j > 0) {
            // If the characters match, this character is definitely part of the LCS
            if (text1[i - 1] == text2[j - 1]) {
                lcs_str.push_back(text1[i - 1]);
                i--; // Move diagonally up-left
                j--;
            } 
            // If they don't match, move to the cell with the larger value to follow the optimal path
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--; // Move straight up
            } else {
                j--; // Move straight left
            }
        }
        
        // The string was collected backwards, so reverse it to get the correct chronological order
        reverse(lcs_str.begin(), lcs_str.end());
        return lcs_str;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        // Step 1: Extract the LCS string using the helper function
        string lcsstr = getLCS(str1, str2);
        
        int m = str1.size(), n = str2.size(), s = lcsstr.size();
        
        // Step 2: Use three pointers to merge str1 and str2 using lcsstr as an anchor point
        int i = 0; // Pointer for str1
        int j = 0; // Pointer for str2
        int k = 0; // Pointer for lcsstr
        string ans = "";
        
        // Loop through each character of the LCS string
        while (k < s) {
            // Add all characters from str1 that appear BEFORE the current LCS anchor character
            while (i < m && str1[i] != lcsstr[k]) {
                ans += str1[i];
                i++;
            }
            
            // Add all characters from str2 that appear BEFORE the current LCS anchor character
            while (j < n && str2[j] != lcsstr[k]) {
                ans += str2[j];
                j++;
            }
            
            // Add the shared LCS character exactly ONCE to keep the supersequence minimal
            ans += lcsstr[k];
            
            // Move all three pointers forward past the matched anchor character
            k++;
            i++;
            j++;
        }
        
        // Step 3: Pick up any leftover characters remaining after the last LCS character
        
        // Add remaining trailing characters of str1 (if any)
        while (i < m) {
            ans += str1[i];
            i++;
        }
        
        // Add remaining trailing characters of str2 (if any)
        while (j < n) {
            ans += str2[j];
            j++;
        }
        
        return ans;
    }
};