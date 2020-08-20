class Solution {
public:
    //vector<int> as ;
    vector<int> dfs(vector<int> a){
       for(int i = 1;i<a.size();i++){
           if(a[i]<0&&a[i-1]>0){
            if(abs(a[i])>abs(a[i-1])){
               
               a[i-1]=0;
                }else if(abs(a[i])<abs(a[i-1])){
               a[i]=a[i-1];
               a[i-1]=0;
                }else if(abs(a[i])==abs(a[i-1])){
                 a[i]=0;
                a[i-1]=0;
                
            }
        }
           
       }
        
        vector<int>next;
        int flag=0;
        for(auto i:a){
            if(i!=0)next.push_back(i);
            else if(i==0){flag=1;}
        }
        if(flag){
           return dfs(next);
        }
        return next;
        
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.size()<=1)return asteroids;
        return dfs(asteroids);
    }
};
