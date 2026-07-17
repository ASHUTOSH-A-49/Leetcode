class Solution {
public:
void DFSFill(vector<vector<int>> &image,int sr,int sc,int c,int color){
    if(sr>=image.size() || sc>=image[0].size() || sr<0 || sc<0) return;
    if(image[sr][sc]!=c) return;
    image[sr][sc] = color;
    DFSFill(image,sr,sc+1,c,color); //right
    DFSFill(image,sr+1,sc,c,color); //down
    DFSFill(image,sr-1,sc,c,color); //up
    DFSFill(image,sr,sc-1,c,color); //right
    return;
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cellcolor = image[sr][sc];
        if (cellcolor == color) return image; 
        DFSFill(image,sr,sc,cellcolor,color);
        return image;
    }
};