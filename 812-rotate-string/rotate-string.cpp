class Solution {
public:
    bool rotateString(string s, string goal) {
        string full  = s+s;
        if(s.size()!=goal.size()) return false;
        int n = goal.size();
        int l = 0,r = n-1;
        bool check =  false;
        while(r<full.size()){
            string newst = "";
            for(int i = l;i<=r;i++){
                newst+=full[i];
            }
            if(newst==goal){
                check = true;
                break;
            }
            l++;r++;
        }
        return check;
    }
};