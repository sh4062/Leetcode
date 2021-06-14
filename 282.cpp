class Solution {
public:
    string n;
    int t;
    vector<string>res;
    vector<string> addOperators(string num, int target) {
        n=num;
        t=target;
        //n.push_back(num[0]-'0');
        string s="";
        dfs(0,0,0,s);
        return res;

    }

    void dfs(int index,long cur,int pre,string cs){
        if(index>n.size())return ;
        //cout<<cs<<":"<<cur<<endl;
        if(cur==t&&index==n.size()){
            res.push_back(cs);
        }
        for(int i = index+1;i<=n.size();i++){
            string cur_num = n.substr(index, i-index);
            if(cur_num.size()>1&&cur_num[0]=='0')break;
            long c = stol(cur_num);
            if(cs.size()==0)dfs(i,cur+c,c,cur_num);
            else{
            dfs(i,cur+c,c,cs+'+'+cur_num);
            dfs(i,cur-c,-c,cs+'-'+cur_num);
            dfs(i,cur-pre+pre*c,pre*c,cs+'*'+cur_num);
            }
            
        }
    }
};
