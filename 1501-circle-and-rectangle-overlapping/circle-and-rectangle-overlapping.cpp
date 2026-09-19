class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int sx = max(x1,min(xCenter,x2)), sy = max(y1,min(yCenter,y2));
        int delx = sx-xCenter, dely = sy-yCenter;
        int d = sqrt(delx*delx + dely*dely);
        return (d<=radius);
    }
};