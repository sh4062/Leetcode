class Solution {
public:
     long long int cnt =0;
    vector<int>l;
    int fin;
     long long int meme[101][201]={-1};
     long long  int dfs(int cur,int fuel_left){
        if(meme[cur][fuel_left]!=-1)return meme[cur][fuel_left];
        long long int res = 0;
        if(cur==fin){
             res+=1;
        }
        
        
        for(int i = 0;i<l.size();i++){
            if(i==cur)continue;
            if(abs(l[i]-l[cur])<=fuel_left){
                res+=dfs(i,fuel_left-abs(l[i]-l[cur]));
                res%=1000000007;
            }
        }
        meme[cur][fuel_left]=res;
        return res;

    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        l=locations;
        fin=finish;
        memset(meme,-1,sizeof(meme));
        cnt =dfs(start,fuel);
        return cnt%1000000007;;//

    }

};
