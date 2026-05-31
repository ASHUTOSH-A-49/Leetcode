class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long cmass = mass;
        asteroids.push_back(mass);
        sort(asteroids.begin(),asteroids.end());
        vector<int> smol,big;
        int idx;
        for(int i = 0;i<asteroids.size();i++){
            if(asteroids[i]==mass){
                while(i<asteroids.size() && asteroids[i]==mass){
                    i++;
                }
                idx = i-1;
                break;
            }
        }
        for(int i = 0;i<idx;i++){
            smol.push_back(asteroids[i]);
        }
        for(int i = idx+1;i<asteroids.size();i++){
            big.push_back(asteroids[i]);
        }

        while(big.size()>0){
            long long newmass = cmass;
            
            while(newmass<big[0]){
                if(smol.size()==0) break;
                newmass+= smol[smol.size()-1];
                int remidx = smol.size()-1;
                smol.erase(smol.begin()+remidx);
            }
            if(big.size()==0) break;
            if(newmass<big[0]) return false;
            newmass+=big[0];
            big.erase(big.begin());
            cmass = newmass;
        }

        if(big.size()>0) return false;
        return true;

    }
};