class Solution {
public:
int result = INT_MAX;
vector<int>permres;
void solve(vector<int> & nums, vector<bool> & visited,int score,vector<int> & Perm){
    if(score>result) return; //pruning
    if(Perm.size()==nums.size()){
        score+=abs(Perm.back()-nums[Perm[0]]);
        if(result>score){
            result = score;
            permres = Perm;
        }
        return;
        
    }
    int n = nums.size();
    //start with 0 as it will give cyclic lexicographically smallest req ans
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            Perm.push_back(i);
            int s = Perm.size();
            solve(nums,visited,score+abs(Perm[s-2]-nums[Perm[s-1]]),Perm);
            //backtrack
            Perm.pop_back();
            visited[i] = false; 
        }
    }

}
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> Perm = {0};
        vector<bool> visited(n,false);
        visited[0] = true;
        int score = 0;
        solve(nums,visited,score,Perm);
        return permres;
    }
};