class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> elem = {-1,0};
        int prevelem = intervals[0][1];
        for(int i = 0;i<intervals.size();i++){
            if(elem[0]==-1){
                elem[0] = intervals[i][0];   
            }
            if(intervals[i][0]<=prevelem+1){
                prevelem = max(prevelem,intervals[i][1]);
            }
            else{
                elem[1] = prevelem;
                ans.push_back(elem);
                elem[0]  = intervals[i][0];
                prevelem = intervals[i][1];
            }
        }
        elem[1] = prevelem;
        ans.push_back(elem);
        return ans;
    }
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> merged = merge(occupiedIntervals); 
        for(int i = 0;i<merged.size();){
            int strt = merged[i][0],end = merged[i][1];
            if(freeStart>end || freeEnd < strt){
                i++;
            }
            else if(freeStart<=strt && freeEnd>=end){
                merged.erase(merged.begin()+i);
            }
            else if(freeStart>strt && freeEnd<end){
                merged[i][1] = freeStart-1;
                merged.insert(merged.begin()+i+1,{freeEnd+1,end});
                i+=2;
            }
            else if(freeStart>strt && freeStart<=end){
                merged[i][1] = freeStart-1;
                i++;
            }
            else{
                merged[i][0] = freeEnd+1;
                i++;
            }
        }
        return merged;
    }
};