class Solution {
public:

    int res = INT_MAX;
    vector<int> job;
    
    int kk;
    //vector<vector<int>>v;
    vector<int>v;
    void dfs(int index,int cur){
       
        if(index>job.size())return ;
        if(index == job.size()){
            for(auto i:v){
                if(i==0)return;
            }
            int imax = 0;
            for(auto i:v){
                imax = max(imax,i);
            }
            res = min(imax,res);
            return ;
        }
        if (cur >= res)
        return ;
        // unordered_set<int> workTime;
            for(int j = 0;j<kk;j++){
            //    if (workTime.count(v[j]))
            //     continue;
            //     workTime.insert(v[j]);
                v[j]+=(job[index]);
                dfs(index+1,max(cur, v[j]));
                v[j]-=job[index];
                if(v[j]==0)
                break;
            }
            

    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        v.resize(k);
        kk=k;
        job=jobs;
        vector<int> vis;
        vis.resize(jobs.size(),0);
        // sort(begin(job), end(job), greater<int>());
        dfs(0,0);

        return res;

    }
};
