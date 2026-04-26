class Solution {
public:
int solve(vector<vector<int>>& requests,vector<int> & arr,int n,int & req,int i){
    int m = requests.size();
    if(i==m) {
        for(int i = 0;i<n;i++){
            if(arr[i]!=0) return 0;
        }
        return req;
    }
    int temp1 = arr[requests[i][0]];
    int temp2 = arr[requests[i][1]];
    arr[requests[i][0]] = arr[requests[i][0]]-1;
    arr[requests[i][1]] = arr[requests[i][1]]+1;
    int temp3 = req;
    req = req+1;
    int take = solve(requests,arr,n,req,i+1);
    //backtrack
    arr[requests[i][0]] = temp1;
    arr[requests[i][1]] = temp2;
    req = temp3;
    int ntake = solve(requests,arr,n,req,i+1);
    return max(take,ntake);

}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int req = 0;
        vector<int> arr (n,0);
        return solve(requests,arr,n,req,0);
    }
};