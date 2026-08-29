

class Solution {
public:
    int solve(int ql,int qr,int skip,vector<vector<int>> & g){
        if(ql>qr) return 0;
        if(skip<ql || skip>qr) return g[ql][qr];
        int l = (skip>ql) ? g[ql][skip-1] : 0;
        int r = (skip<qr) ? g[skip+1][qr] : 0;
        return gcd(l,r);
        
    }
    int maxValidSplits(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        vector<vector<int>> gcdArr(n,vector<int>(n,0));
        for(int i = 0;i<n;i++){
            gcdArr[i][i] = nums[i];
            for(int j = i+1;j<n;j++){
                gcdArr[i][j] = gcd(gcdArr[i][j-1],nums[j]);
            }
        }
        int maxsplit = 0;
        for(int i = -1;i<n;i++){
            int split = 0;
            int ub = (i==-1) ? n-1 : n-2;
            for(int j = 0;j<ub;j++){
                int l = j;
                if(i!=-1 && i<=j) l = j+1;
                int lgcd = solve(0,l,i,gcdArr);
                int rgcd = solve(l+1,n-1,i,gcdArr);
                if(lgcd==rgcd) split++;
            }
            maxsplit = max(split,maxsplit);
        }
        return maxsplit;
    }
};