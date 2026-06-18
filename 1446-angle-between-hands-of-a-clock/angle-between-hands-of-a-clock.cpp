class Solution {
public:
    double angleClock(int hour, int minutes) {
        double anglehr = (double)(30*hour + 0.5 * minutes);
        double anglemin = (double)(minutes*6);
        if(anglemin>= anglehr) return min(360-anglemin + anglehr,anglemin-anglehr);
        return min(360-anglehr + anglemin, anglehr-anglemin);
    }
};