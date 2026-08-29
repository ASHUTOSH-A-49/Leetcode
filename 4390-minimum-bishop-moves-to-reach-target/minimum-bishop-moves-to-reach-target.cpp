class Solution {
public:
    
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int srcpar = source[0]+source[1];
        int tarpar = target[0]+target[1];
        if((srcpar%2) != (tarpar%2)) return -1;
        if(source[0]==target[0]&& source[1]==target[1]) return 0;
        if(abs(source[0]-target[0])==abs(source[1]-target[1])) return 1;
        return 2;
        
    }
};