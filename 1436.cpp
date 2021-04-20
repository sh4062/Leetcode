class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string res;
        string tmp;
        queue<string>q;
        q.push(paths[0][0]);
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            //cout<<tmp<<endl;
            for(auto i:paths){
                if(i[0]==tmp){
                    q.push(i[1]);
                }
            }
        }
        return tmp;

    }
};
