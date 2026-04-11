class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> & elem,int k,int n,int prev){
        if(k==0){
            if(n==0){
              ans.push_back(elem);
            return;  
            }
            return;
        }
        if(n<0) return;
        for(int i= 1;i<10;i++){
            if(i>prev){
                elem.push_back(i);
            solve(elem,k-1,n-i,i);
            elem.pop_back();
            }
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> elem;
        solve(elem,k,n,0);
        return ans;
    }
};