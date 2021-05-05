class Solution {
public:
    vector<int>hour={1,2,4,8};
    vector<int>minute={1,2,4,8,16,32};
    vector<string>  res;
    vector<int> v;
    unordered_set<string>S;
    void dfs(int n,int m,int left,int sums1,int sums2){
        if(left==0){
            if(sums2>59||sums1>11)return;
            string tmp1=to_string(sums1),tmp2;
            // if(sums1>10)tmp1=to_string(sums1);
            // else{
            //     tmp1 = "0"+to_string(sums1);
            // }
            if(sums2>9)tmp2=to_string(sums2);
            else{
                tmp2 = "0"+to_string(sums2);
            }
            if(S.find(tmp1+":"+tmp2)==S.end()){
                S.insert(tmp1+":"+tmp2);
                res.emplace_back(tmp1+":"+tmp2);
            }
            

        }
        if(n>hour.size()||m>minute.size())return;
        for(int i = n;i<hour.size();i++){
            dfs(i+1,m,left-1,sums1+hour[i],sums2);
        }
        for(int i = m;i<minute.size();i++){
            dfs(n,i+1,left-1,sums1,sums2+minute[i]);
        }
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        dfs(0,0,turnedOn,0,0);
       
        return res;
        

    }
};
