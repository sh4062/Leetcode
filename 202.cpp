class Solution {
public:
    set<int>S;
    int get_next(int cur){
        int ret =0;
        while(cur){
            int tmp = cur%10;
            cur/=10;
            ret+=tmp*tmp;
        }
        return ret;
    }
    bool isHappy(int n) {
        if(n==1)return true;
        while(1){
            int nex = get_next(n);
            n=nex;
            if(S.find(n)==S.end()){
                S.insert(n);
            }else if(n==1){
                return true;
            }else if(S.find(n)!=S.end()){
                return false;
            }
        }
        return false;

    }
};
