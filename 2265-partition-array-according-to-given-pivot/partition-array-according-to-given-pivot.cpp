class Solution {
public:

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> large,eq,res;
            for(int i :nums){
            if(i<pivot) res.push_back(i);
            else if(i==pivot) eq.push_back(i);
            else large.push_back(i);
            }
            for(int i:eq) res.push_back(i);
            for(int i:large) res.push_back(i);
            
        
        return res;
        
    }
};