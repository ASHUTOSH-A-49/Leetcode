class Solution {
public:
    int UBidx(vector<vector<int>> & arr,int target){
        int ans = -1;
        int l = 0,h = arr.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(arr[mid][0]<target){
                l = mid+1;
            }else{
                ans = mid;
                h = mid-1;
            }
        }
        return ans;
    }
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int ptr1 = 0,ptr2 = 0;
        vector<vector<int>> agg;
        while(ptr1 < series1.size() && ptr2<series2.size()){
            int ts,val;
            if(series1[ptr1][0]==series2[ptr2][0]){
                ts = series1[ptr1][0];
                val = series1[ptr1][1] + series2[ptr2][1];
                ptr1++;ptr2++;
            }
            else if(series1[ptr1][0]<series2[ptr2][0]){
                ts = series1[ptr1][0];
                int idx2 = UBidx(series2,series1[ptr1][0]);
                if(idx2!=-1){
                    val = series1[ptr1][1] + series2[idx2][1];
                }else{
                    val = series1[ptr1][1];
                }
                ptr1++;
            }else{
                ts = series2[ptr2][0];
                int idx1 = UBidx(series1,series2[ptr2][0]);
                if(idx1!=-1){
                    val = series2[ptr2][1]+series1[idx1][1];
                }else{
                    val = series2[ptr2][1];
                }
                ptr2++;
            }
            agg.push_back({ts,val});
        }

        while(ptr1<series1.size()){
            int ts,val;
            ts = series1[ptr1][0];
            int idx2 = UBidx(series2,series1[ptr1][0]);
            if(idx2!=-1){
                val = series1[ptr1][1] + series2[idx2][1];
            }else{
                val = series1[ptr1][1];
            }
            ptr1++;
            agg.push_back({ts,val});
        }
        while(ptr2<series2.size()){
            int ts,val;
            ts = series2[ptr2][0];
            int idx1 = UBidx(series1,series2[ptr2][0]);
            if(idx1!=-1){
                val = series2[ptr2][1] + series1[idx1][1];
            }else{
                val = series2[ptr2][1];
            }
            ptr2++;
            agg.push_back({ts,val});
        }
        return agg;

    }
};