class Solution {
public:
    int paths(int a,int b,int &m,int &n,vector<vector<int>> &memo){
        if(a>m-1 || b>n-1) return 0;
        if(a==m-1 && b==n-1) return 1;
        if(memo[a][b]!=-1) return memo[a][b];
        int r = paths(a,b+1,m,n,memo);
        int d = paths(a+1,b,m,n,memo);
        return memo[a][b] =  r+d;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return paths(0,0,m,n,memo);
        
    }
};