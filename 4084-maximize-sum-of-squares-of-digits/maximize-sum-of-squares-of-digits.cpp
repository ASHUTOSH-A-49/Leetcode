#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9||sum<1){
            return "";
        }
        string result_str="";
        int remaining_sum=sum;
        for(int i=0;i<num;++i){
            int start_digit=(i==0)?1:0;
            for(int d=9;d>=start_digit;--d){
                int left_digits=num-1-i;
                if(remaining_sum-d>=0&&remaining_sum-d<=left_digits*9){
                    result_str+=to_string(d);
                    remaining_sum-=d;
                    break;
                }
            }
        }
        return result_str;
    }
};