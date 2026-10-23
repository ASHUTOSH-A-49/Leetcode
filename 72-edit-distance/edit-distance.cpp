class Solution {
public:
//MEMOIZATION APPROACH
vector<vector<int>> dp;
    int solve(int i,int j,string &w1,string&w2,int &m,int &n){
        if(i==m && j==n) return 0;
        if(i==m) return n-j;
        if(j==n) return m-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ins,del,repl;
        
        repl = ((w1[i]==w2[j])?0:1)+solve(i+1,j+1,w1,w2,m,n);
        ins = 1+solve(i,j+1,w1,w2,m,n);
        del = 1+solve(i+1,j,w1,w2,m,n);
        return dp[i][j] = min({repl,ins,del});

    }
    int minDistance(string word1, string word2) {
        int m = word1.size(),n = word2.size();
        dp.assign(m,vector<int>(n,-1));
        return solve(0,0,word1,word2,m,n);
    }
};