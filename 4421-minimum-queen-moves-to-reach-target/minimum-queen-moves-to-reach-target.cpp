class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sx = source[0],sy = source[1],tx = target[0],ty = target[1];
        if(sx==tx && sy==ty) return 0;
        else if(sx==tx || sy==ty||  abs(sx-tx)==abs(sy-ty)) return 1;
        return 2;
        
    }
};