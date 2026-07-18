class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN,mini = INT_MAX;
        for(int i :nums){
            maxi = max(maxi,i);
            mini = min(mini,i);
        }
        return gcd(maxi,mini);
    }
};