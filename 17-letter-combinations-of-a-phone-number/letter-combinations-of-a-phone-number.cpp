class Solution {
public:
vector<string> ans;
    void solve(string digits,int ind,string  el){
        //base 
        if(ind==digits.size()){
            ans.push_back(el);
            return;
        }
        // recursion and backtracking calls - 3 calls each 
        int dig = digits[ind]-'2';
        if(dig<5){
            solve(digits,ind+1,el+static_cast<char>('a' + (dig * 3)));
            solve(digits,ind+1,el+static_cast<char>('a'+dig*3+1));
            solve(digits,ind+1,el+static_cast<char>('a'+dig*3+2));
        }else{
            char strt = 'a' + 15;
            if(dig==5){
                solve(digits,ind+1,el+static_cast<char>(strt+0));
                solve(digits,ind+1,el+static_cast<char>(strt+1));
                solve(digits,ind+1,el+static_cast<char>(strt+2));
                solve(digits,ind+1,el+static_cast<char>(strt+3));
            }else if(dig==6){
                solve(digits,ind+1,el+static_cast<char>(strt+4));
                solve(digits,ind+1,el+static_cast<char>(strt+5));
                solve(digits,ind+1,el+static_cast<char>(strt+6));
            }else{
                solve(digits,ind+1,el+static_cast<char>(strt+7));
                solve(digits,ind+1,el+static_cast<char>(strt+8));
                solve(digits,ind+1,el+static_cast<char>(strt+9));
                solve(digits,ind+1,el+static_cast<char>(strt+10));
            }
        }
         
        
    }
    vector<string> letterCombinations(string digits) {
        string el = "";
        solve(digits,0,el);
        return ans;
    }
};