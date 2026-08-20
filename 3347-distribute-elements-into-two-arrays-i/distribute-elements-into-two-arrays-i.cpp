class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> a1,a2;
        int l1=nums[0],l2=nums[1];
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        
        for(int i=2;i<n;i++){
            if(l1>l2) {
                a1.push_back(nums[i]);
                l1=nums[i];
            }
            else {
                a2.push_back(nums[i]);
                l2=nums[i];
            }
        }
        vector<int> res;
        for(int i=0;i<a1.size();i++){
            res.push_back(a1[i]);
        }
        for(int i=0;i<a2.size();i++){
            res.push_back(a2[i]);
        }
        return res;
    }
};