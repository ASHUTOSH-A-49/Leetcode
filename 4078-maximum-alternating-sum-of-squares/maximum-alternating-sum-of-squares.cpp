class Solution {
public:
// O(n) approach - quickselect or nth element (partial sort nth element such that all to left of it <=nth element and to right of it are > nth element)
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        nth_element(begin(nums),begin(nums)+n/2,end(nums));// or use quick select to partial sort
        long long left = accumulate(begin(nums),begin(nums)+n/2,0LL);
        long long right = accumulate(begin(nums)+n/2,end(nums),0LL);
        return right-left;

    }
};