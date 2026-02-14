class Solution {
public:
    string largestOddNumber(string num) {
        int l = 0,r = num.size()-1;
        string ans = "";
        while(r>=l){
            if(num[r]%2==0){
                r--;
            }else{
                break;
            }
        }
        if(r<l){
            return ans;
        }
        for(int i = l;i<=r;i++){
            ans+=num[i];
        }
        return ans;
    }
};