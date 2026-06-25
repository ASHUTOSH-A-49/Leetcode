class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n= nums.size();
        map<int,int> grps; //ordered  = sorted map
        for(int i:nums) grps[i]++;
        while(!grps.empty()){
            int strt = grps.begin()->first;
            for (int i = 0; i<k; i++) {
                int curr =strt+i; //if next consec elem exist
                if (grps.find(curr) == grps.end()) {
                    return false;
                }
                grps[curr]--;
                if (grps[curr] == 0) {
                    grps.erase(curr);
                }
            }
        }
        return true;
    }
};