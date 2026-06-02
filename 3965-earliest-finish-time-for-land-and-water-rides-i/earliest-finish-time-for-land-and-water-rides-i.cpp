class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<vector<int>> waterRides,LandRides;
        for(int i = 0;i<landStartTime.size();i++){

            LandRides.push_back({landStartTime[i],landStartTime[i]+landDuration[i]});
        }
        for(int i = 0;i<waterStartTime.size();i++){
            
            waterRides.push_back({waterStartTime[i],waterStartTime[i]+waterDuration[i]});
        }
        int t1 = 4000,t2 = 4000;
        sort(waterRides.begin(),waterRides.end());
        sort(LandRides.begin(),LandRides.end());
        for(vector<int> u:LandRides){
            int tnew1 = u[1];
            for(vector<int> v:waterRides){
                int tnew2;
                if(tnew1>v[0]){
                    tnew2 =tnew1+v[1]-v[0];
                }else{
                    tnew2 = v[1]; 
                }
                t1 = min(t1,tnew2);
            }
        }
        for(vector<int> u:waterRides){
            int tnew1 = u[1];
            for(vector<int> v:LandRides){
                int tnew2;
                if(tnew1>v[0]){
                    tnew2 =tnew1+v[1]-v[0];
                }else{  
                    tnew2 = v[1]; 
                    // cout<<tnew2<<endl;
                }
                t2 = min(t2,tnew2);
            }
        }
        for(vector<int> v:waterRides){
            cout<<"{"<<v[0]<<" "<<v[1]<<"}";
        }
        cout<<endl;
        for(vector<int> v:LandRides){
            cout<<"{"<<v[0]<<" "<<v[1]<<"}";
        }
        cout<<endl;
        cout<<t1<<" "<<t2;
        return min(t1,t2);
    }
};