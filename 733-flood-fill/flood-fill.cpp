class Solution {
public:
void DFSFill(vector<vector<int>> &image,vector<vector<int>> &visited,int sr,int sc,int c,int color){
    if(sr>=image.size() || sc>=image[0].size() || sr<0 || sc<0) return;
    if(visited[sr][sc]) return;
    if(image[sr][sc]!=c) return;
    visited[sr][sc] = 1;
    image[sr][sc] = color;
    DFSFill(image,visited,sr,sc+1,c,color); //right
    DFSFill(image,visited,sr+1,sc,c,color); //down
    DFSFill(image,visited,sr-1,sc,c,color); //up
    DFSFill(image,visited,sr,sc-1,c,color); //right
    return;
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cellcolor = image[sr][sc];
        int m = image.size(),n = image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        DFSFill(image,visited,sr,sc,cellcolor,color);
        return image;
    }
};