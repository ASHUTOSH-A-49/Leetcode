class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 0,rem = 10;
        while(n>=rem && rem>0){
            n-=rem;
            rem--;
            turn = !turn;
        }
        cout<<turn<<endl;
        return turn;
    }
};