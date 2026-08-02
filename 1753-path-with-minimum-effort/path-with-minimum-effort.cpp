class Solution {
public:
    bool getPath(int k,vector<vector<int>> &heights){
        int n = heights.size(),m = heights[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        int drow[] = {-1,1,0,0}; //up down left right
        int dcol[] = {0,0,-1,1};

        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                auto[r,c] = q.front();
                q.pop();
                if(r==n-1 && c==m-1) return true;
                for(int i = 0;i<4;i++){
                    int nr = r+drow[i];
                    int nc = c+dcol[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && abs(heights[nr][nc]-heights[r][c])<=k){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {

        int l = 0,h = 1e6;
        int ans;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(getPath(mid,heights)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};