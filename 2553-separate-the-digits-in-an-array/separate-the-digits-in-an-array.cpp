
#include<bits/stdc++.h>

class Solution {
public:
vector<int> ans;
void solve(int n){
    if(n==0){
        ans.push_back(0);
        return;

    } else{
    int digits = log10(n);
    int divisor = pow(10, digits);

    while (divisor > 0) {
        int digit = n/ divisor;
        ans.push_back(digit);
        n %= divisor;
        divisor /= 10;
    }
    return;
    }
}
    vector<int> separateDigits(vector<int>& nums) {
        for(int i:nums){
            solve(i);
        }
        return ans;
    }
};