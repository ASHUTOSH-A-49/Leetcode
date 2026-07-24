class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> nums1(nums.begin(),nums.end());
        vector<int> uniqnum(nums1.begin(),nums1.end());

        int n = uniqnum.size();
        unordered_set<int> Xorpairs;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                Xorpairs.insert(uniqnum[i]^uniqnum[j]);
            }
        }

        unordered_set <int> Xortrip;
        for(int i = 0;i<n;i++){
            for(int k:Xorpairs){
                Xortrip.insert(uniqnum[i]^k);
            }
        }
        return Xortrip.size();
        
    }
};