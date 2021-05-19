class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m = (double)minutes/5;
        double h = (double)hour+m/12;
        double sum = 0;
        if(m == h || (m == 0 && h == 12)){
            return sum;
        }
        sum = abs(m-h)/12*360;
        if(sum > 180){
            sum = 360-sum;
        }
        return sum;
        
    }
};
