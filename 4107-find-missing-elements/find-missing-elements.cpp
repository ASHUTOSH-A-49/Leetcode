class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi= 0,mini=1e9;
        unordered_set<int> hash;
        for(int i:nums){
            maxi=max(maxi,i);
            mini=min(mini,i);
            hash.insert(i);
        }
        vector<int> v;
        for(int i=mini;i<=maxi;i++){
            if(hash.find(i)!=hash.end()){
                continue;
            }
            else{
                v.push_back(i);
            }
        }
        return v;
    }
};