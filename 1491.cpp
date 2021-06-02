class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double s = accumulate(salary.begin(),salary.end(),0);
        s-=salary[0];
        s-=salary.back();
        s/=(salary.size()-2);
        return s;

    }
};
