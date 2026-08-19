class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        unordered_map<int,set<int>> mp;
        for(auto r:reservedSeats){
            int row = r[0], seat = r[1];
            mp[row].insert(seat);
        }
        for(auto &[i,s]:mp){
                if(
                    s.find(2)==s.end() && s.find(3)==s.end() && s.find(4)==s.end() && s.find(5)==s.end()
                ){
                    s.insert(4);
                    ans++;
                }
                if (
                    s.find(4)==s.end() && s.find(5)==s.end() && s.find(6)==s.end() && s.find(7)==s.end()
                ){
                    s.insert(6);
                    ans++;
                }
                if(
                    s.find(6)==s.end() && s.find(7)==s.end() && s.find(8)==s.end() && s.find(9)==s.end()
                ){
                    ans++;
                }
        }
        ans+=(n-mp.size())*2;
        return ans;
    }
};