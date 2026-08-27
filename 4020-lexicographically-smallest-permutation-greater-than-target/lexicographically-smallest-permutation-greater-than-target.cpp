class Solution {
public:
string result = "";
    bool solve(string & curr, map<char,int> &mp1,string & target,int i, bool isGreater){
        if(i==target.size()){
            if(isGreater){
                result = curr;
                return true;
            }
            return false;
            //base case;
        }
        for(char ch = 'a';ch<='z';ch++){
            if(mp1[ch]<=0) continue;
            if(isGreater==false && ch<target[i]) continue;
            //do
            curr.push_back(ch);
            mp1[ch]--;
            bool newGr = isGreater || (ch>target[i]);
            //explore
            if(solve(curr,mp1,target,i+1,newGr)) return true;
            //backtrack
            curr.pop_back();
            mp1[ch]++;


        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        string ans = "";
        map<char,int> mp1;
        for(char c:s) mp1[c]++;
        string curr = "";
        solve(curr,mp1,target,0,false);
        return result;
    }
};