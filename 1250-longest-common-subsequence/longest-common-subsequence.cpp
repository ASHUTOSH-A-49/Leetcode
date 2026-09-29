class Solution {
public:
vector<vector<int>> dp;
int solve(int i,int j,string & s1,string & s2){
    if(i<0 || j<0) return 0;
    bool match = (s1[i]==s2[j]);
    if(dp[i][j]!=-1) return dp[i][j];
    if(match) return dp[i][j] =  1+solve(i-1,j-1,s1,s2);
    return dp[i][j] = max(solve(i-1,j,s1,s2),solve(i,j-1,s1,s2));
}
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();
        dp.assign(m,vector<int>(n,-1));
        return solve(m-1,n-1,text1,text2);
    }
};