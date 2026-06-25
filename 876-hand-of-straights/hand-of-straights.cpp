class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        map<int,int> grps; //ordered  = sorted map
        for(int i:hand) grps[i]++;
        while(!grps.empty()){
            int strt = grps.begin()->first;
            for (int i = 0; i < groupSize; i++) {
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