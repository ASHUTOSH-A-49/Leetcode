class Solution {
public:
    
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> cal = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = 0;
        int ams = stoi(arriveAlice.substr(0,2));
        int ame = stoi(leaveAlice.substr(0,2));
        int bms = stoi(arriveBob.substr(0,2));
        int bme = stoi(leaveBob.substr(0,2));

        int ads = stoi(arriveAlice.substr(3,2));
        int ade = stoi(leaveAlice.substr(3,2));
        int bds = stoi(arriveBob.substr(3,2));
        int bde = stoi(leaveBob.substr(3,2));

        float as = ams+((float)ads/100);
        float bs = bms+((float)bds/100);
        float ae = ame+((float)ade/100);
        float be = bme+((float)bde/100);

        cout<<as<<" "<<ae<<" "<<bs<<" "<<be<<endl;

        //1
        if(as>=bs && ae<=be){
            if(ams==ame){
                ans+=ade-ads+1;
            }else{
                ans+=cal[ams-1]-ads+1 + ade;
                for(int i = ams+1;i<ame;i++){
                    ans+=cal[i-1];
                }
            }
            
        }else if(bs>=as && be<=ae){
            cout<<"bs-->be"<<endl;
            if(bms==bme){
                ans+=bde-bds+1;
            }else{
                ans+=cal[bms-1]-bds+1 + bde;
                for(int i = bms+1;i<bme;i++){
                    ans+=cal[i-1];
                }
            }
            
        }else if(as>=bs && as<=be){
            if(ams==bme){
                ans+=bde-ads+1;
            }else{
                ans+=cal[ams-1]-ads+1+bde;
                for(int i = ams+1;i<bme;i++){
                    ans+=cal[i-1];
                }
            }
        }else if(ae>=bs && ae<=be){
            // bs-->ae
            cout<<"bs-->ae"<<endl;
            if(ame==bms){
                ans+=ade-bds+1;
            }else{
                ans+=cal[bms-1]-bds+1+ade;
                for(int i = bms+1;i<ame;i++){
                    ans+=cal[i-1];
                }
            }
        }
        return ans;
    }
};