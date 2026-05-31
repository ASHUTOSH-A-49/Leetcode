class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long newmass= mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i:asteroids){
            if(newmass<i) return false;
            newmass+=i;
        }
        return true;

    }
};