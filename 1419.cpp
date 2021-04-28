class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char,int>mp;
        if(croakOfFrogs.size()<5)return 0;
        vector<int>valid(5,0);
        vector<int>indexs;
        int count = 0;
        int cnt = 0;
        int res = 0;
        for(int i = 0;i<croakOfFrogs.size();i++){
            if(croakOfFrogs[i]=='c'){
                indexs.push_back(i);
                valid[0]++;
            }
            if(croakOfFrogs[i]=='r'){
                valid[1]++;
            }
            if(croakOfFrogs[i]=='o'){
                valid[2]++;
            }
            if(croakOfFrogs[i]=='a'){
                valid[3]++;
            }
            if(croakOfFrogs[i]=='k'){
                valid[4]++;
                count++;
                cnt++;
                res=max(res,valid[0]-valid[4]+1);
                //cout<<valid[0]-valid[4]+1<<endl;
                // if(cnt>1&&i-4==indexs[cnt-1])count--;
                // else if(cnt>1&&indexs.size()>cnt&&i>indexs[cnt-1])count--;
            }
            for(int j = 4;j>=1;j--){
                if(valid[j]>valid[j-1])
                return -1;
                
            }

        }
        for(auto i:croakOfFrogs){
            mp[i]++;
        }
        int maxn = 0;
        for(auto i:mp){
            maxn=max(maxn,i.second);
        }
        for(auto i:mp){
            if(i.second!=maxn)return -1;
        }
        // int cnt = 0;
        // for(int i = 0;i<croakOfFrogs.size();i++){
        //     if(croakOfFrogs[i]=='c'){
        //         if(i+4<croakOfFrogs.size()){
        //         if(croakOfFrogs[i+1]=='r'&&croakOfFrogs[i+2]=='o'&&croakOfFrogs[i+3]=='a'&&croakOfFrogs[i+4]=='k')
                    
                
        //         maxn--;
        //         i+=4;
        //         }
        //     }
        // }
        return res;
        

    }
};
