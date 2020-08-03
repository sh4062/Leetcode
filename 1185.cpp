class Solution {
   vector<string> res = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
     vector<int> mon = {31,28,31,30,31,30,31,31,30,31,30,31};
public:
    string dayOfTheWeek(int day, int month, int year) {
        int y = year-1968;
        int yy=y/4;
        int yyy=1+yy+365*y;
        if(y%4==0)yyy--;
        //if(year>2000)yyy++;
        if(month<2){
           
            return res[(yyy+day-1)%7];
        }else if(year%4==0){
            for(int i = 0;i<month-1;i++){
                yyy+=mon[i];
                
            }if(month>2)yyy+=1;
             
            return res[(yyy+day-1)%7];
            
        }else{
            //cout<<yyy;
            for(int i = 0;i<month-1;i++){
                yyy+=mon[i];
                
            }
            //cout<<yyy;
            return res[(yyy+day-1)%7];
            
        }
        return res[(yyy+day-1)%7];
    }
};