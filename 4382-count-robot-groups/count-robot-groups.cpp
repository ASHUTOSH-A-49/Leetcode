class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int ridx = n-1,lidx = n-1,s = speed[n-1],cnt = 1;
        for(int i = n-2;i>=0;i--){
            if(position[lidx]-position[i]<=distance){
                lidx = i;
                continue;
            }
            if(speed[i]>speed[ridx]){
                lidx = i;
                continue;
            }
            cout<<i<<" "<<lidx<<" "<<ridx;
            cnt++;
            ridx = i;
            lidx = i;
            s = speed[i];
        }
        return cnt;

    }
};