class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        string hstrt = startTime.substr(0,2);
        string mstrt = startTime.substr(3,2);
        string sstrt = startTime.substr(6,2);

        int hst = stoi(hstrt),mst = stoi(mstrt),sst = stoi(sstrt);

        string hend = endTime.substr(0,2);
        string mend = endTime.substr(3,2);
        string send= endTime.substr(6,2);

        int he = stoi(hend),me = stoi(mend),se = stoi(send);

        int startTotal = hst*3600+mst *60+sst;
        int endTotal = he*3600+ me *60+se;
        
        if (endTotal<startTotal) {
            endTotal+=24*3600;
        }
        return endTotal - startTotal; 
    }
};