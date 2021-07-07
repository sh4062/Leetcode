class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int>mp;
        sort(deliciousness.begin(),deliciousness.end());
        for(auto i:deliciousness){
            mp[i]++;
        }
        int res = 0;
        for(int i = 1;i<=1024*1024*4;i*=2){
            for(int j = 0;j<deliciousness.size();j++){
            if(i-deliciousness[j]<deliciousness[j])continue;
            if(mp.find(i-deliciousness[j])!=mp.end()){
                //cout<<i-deliciousness[j]<<endl;
                if(i-deliciousness[j]==deliciousness[j]){
                    if(mp[deliciousness[j]]<=1)continue;
                    if(mp[deliciousness[j]]==2)res+=1;
                    else res+=(long(mp[deliciousness[j]])*(long(mp[deliciousness[j]]-1))/2%(1000000007));
                    j+=mp[deliciousness[j]]+1;

                }else{
                    res+=mp[i-deliciousness[j]];
                }
            }
            }

        }
        return res;

    }
}; 
