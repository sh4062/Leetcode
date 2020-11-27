class Solution {
public:
    string simplifyPath(string path) {
        if(path[path.size()-1]!='/'){
            path=path+'/';
        }
        vector<string> v;
        deque<string> vv;
        string s;
        int level =0;
        for(int i = 1;i<path.size();i++){
            
            if(path[i]=='/'){
                v.push_back(s);
                s="";
            }else{
                s.push_back(path[i]);
            }
        }
        for(auto i:v){
            if(i=="."||i==""){
                
            }else if(i==".."){
                level-=1;
                if(vv.size()>0)
                vv.pop_front();
            }else{
                vv.push_front(i);
                level++;
            }
        }
        //cout<<level<<endl;
        // for(auto i:vv){
        //     cout<<i<<endl;
        // }
        string res="/";
        while(!vv.empty()){
            if(vv.size()>1)
            res+=vv.back()+"/";
            else res+=vv.back();
            vv.pop_back();
        }
        return res;
    }
};
