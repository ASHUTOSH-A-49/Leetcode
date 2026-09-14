class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[0],x2 = rec1[2],y1= rec1[1],y2 = rec1[3];
        int rx1=rec2[0],rx2 = rec2[2],ry1= rec2[1],ry2 = rec2[3];
        bool xcross=min(x2,rx2)>max(x1,rx1);
        bool ycross=min(y2,ry2)>max(y1,ry1);
        return xcross&&ycross;
    }
};