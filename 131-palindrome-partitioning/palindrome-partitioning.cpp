class Solution {
public:
bool checkPal(string s,int idx,int i){
    string s2 = s.substr(idx,i-idx+1);
    int n = s2.size()-1;
    for(int i = 0;i<=s2.size()/2;i++){
        if(s2[i]!=s2[n-i]) return false;
    }
    return true;
}
vector<vector<string>> ans;
void solve(string & s, vector<string> & str,int idx){
    if(idx==s.size()){
        ans.push_back(str);
        cout<<1<<" ";
        return;
    }
    // i goes from idx to n each time on checking all possible splits 
    for(int i = idx;i<s.size();i++){
        if(checkPal(s,idx,i)){
            str.push_back(s.substr(idx,i-idx+1));
            //explore
            solve(s,str,i+1);
            str.pop_back();//backtrack

        }
    }
    
}
    vector<vector<string>> partition(string s) {
        vector<string> str;
        solve(s,str,0);
        return ans;
    }
};