class Solution {
public:
    // bool isadj(vector<int>& nums){
    //     for(int i = 0)
    // }
    vector<long long> mergeAdjacent(vector<int>& nums) {
        bool check = true;
        vector<long long> num2;
        for (int i = 0; i < nums.size(); i++) {
            long long a = nums[i];
            int n = num2.size();
            while(n>0 && num2[n-1]==a){
                a+=num2[n-1];
                num2.erase(num2.end());n--;
            }
            num2.push_back(a);
        }
        // int n = num2.size();
        // int i = 0;
    
        return num2;
    }
};