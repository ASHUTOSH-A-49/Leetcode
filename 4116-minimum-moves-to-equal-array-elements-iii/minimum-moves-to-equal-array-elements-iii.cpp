class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxel = 0;
        for(int i:nums) maxel = max(maxel,i);
        int sum = 0;
        for(int i:nums){
            sum+= maxel-i;
        }
        return sum;
    }
};