class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int x = target[0],y = target[1],minmanh = 115;
        int n = drones.size();
        for(int i = 0;i<n;i++){
            auto d = drones[i];
            int dx = d[0],dy = d[1],r = d[2];
            int manh = abs(dx-x) + abs(dy-y);
            if(manh<=r) {
                if(manh<minmanh) {
                    minmanh  = manh;
                    ans = i;
                }
            }
        }
        return ans;
    }
};