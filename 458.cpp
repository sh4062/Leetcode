class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int fenshu = minutesToTest/minutesToDie;
        int bf = buckets/fenshu;
        if(fenshu==1){
        int index = 0;
        while(pow(2,index)<bf){
            index++;
        }
        return index;
        }else{
            return ceil(log(buckets)/log(fenshu+1));

        }
        return 0;

    }
};
