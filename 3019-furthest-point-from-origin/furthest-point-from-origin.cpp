class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0,l = 0,emp = 0;
        for(int i = 0;i<moves.size();i++){
            if(moves[i]=='R')r++;
            else if(moves[i]=='L')l++;
            else emp++;
        }
        return (r>=l)?(r+emp-l):(l+emp-r);
    }
};