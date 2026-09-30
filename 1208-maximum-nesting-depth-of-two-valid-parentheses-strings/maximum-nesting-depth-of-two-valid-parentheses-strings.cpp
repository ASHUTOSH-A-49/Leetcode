class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n= seq.size();
        int op=0;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            char c= seq[i];
            int grp;
            if(c=='('){
                op++;
                grp= op%2;
            }else{
                grp=op%2;
                op--;
            }
       
            ans[i]=grp;
        }
        return ans;
    }
};