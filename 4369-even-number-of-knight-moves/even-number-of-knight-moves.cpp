class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int delx = abs(target[0]-start[0]), dely = abs(target[1]-start[1]);
        return (delx%2 == dely%2);
    }
};