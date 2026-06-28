class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1,carry = 0;
        for(int i = n;i>=0;i--){
            if(i==n){
                if(digits[i]+ 1 +carry > 9){
                digits[i] = 0;
                carry = 1;
                }else{
                    digits[i] = digits[i]+1;
                    carry = 0;
                }
            }else{
                if(carry==1){
                    if(digits[i]+carry > 9){
                    digits[i] = 0;
                    carry = 1;
                    }else{
                        digits[i] = digits[i]+carry;
                        carry = 0;
                    }
                }
            }
            
        }
        if(carry!=0) digits.insert(digits.begin(),1);
        return digits;

    }
};