class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==1)return true;
        if(c==0)return true;
        if(c==5)return true;
        unordered_map<long,long>m;
        m[0]=1;
        for(long i = 1;i<=c;i++){
            if(i*i>c||i*i>=INT_MAX)break;
            m[i*i]=1;
            
            if(m.find(c-i*i)!=m.end()){
                return true;
            }
        }
        
        return false;
    }
};
