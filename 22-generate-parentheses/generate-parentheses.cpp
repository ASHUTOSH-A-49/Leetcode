class Solution {
public:
    vector<string> ans;

    void solve(string& par, int op, int cl) {
    if(op == 0 && cl == 0) {
        ans.push_back(par);
        return;
    }
    
    if(op > 0) {
        par.push_back('(');
        solve(par, op - 1, cl);
        par.pop_back(); 
    }
    
    if(cl > op) {
        par.push_back(')');
        solve(par, op, cl - 1);
        par.pop_back(); 
    }
}
    vector<string> generateParenthesis(int n) {
        string par="";
        solve(par,n,n);
        return ans;
    }
};