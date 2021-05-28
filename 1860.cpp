class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int>res(3,0);

        int t = 1;
        while(memory1>=0&&memory2>=0){
            if(memory2>memory1){
                memory2-=t;
                if(memory2<0){
                    memory2+=t;
                    break;
                }

            }else{
                memory1-=t;
                if(memory1<0){
                    memory1+=t;
                    break;
                }
            }
            t++;
        }
        res[0]=t;
        res[1]=memory1;
        res[2]=memory2;


        return res;

    }
};
