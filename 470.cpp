// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int res;
        while(1){
            res=(rand7()-1)*7+rand7();//0-42+1-7=1-49
            if(res<=40)break;//1-40
        }
        return (res/4)%10+1;
        
    }
};
