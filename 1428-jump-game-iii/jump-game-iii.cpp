class Solution {
public:
// TC - O(N) , SC - O(N)
    bool solve(int i,vector<int> & arr,vector<bool> &visited){
        if(i>=arr.size() || i<0) return false;
        if(arr[i]==0) return true;
        if (visited[i]) return false;
        visited[i] = true;
        bool add = solve(i+arr[i],arr,visited);
        bool sub = solve(i-arr[i],arr,visited);
        return (add || sub);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return solve(start,arr,visited);
    }
};