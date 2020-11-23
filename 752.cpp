class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string>q;
        int step=0;
        q.push("0000");
        set<string> visited;
        for(auto i:deadends){
            visited.insert(i);
        }
        while(!q.empty()){
            int size =q.size();
            for(int i = 0;i<size;i++){
                auto node = q.front();
                q.pop();
                if(visited.count(node)){
                    continue;
                }
                if(node==target){
                    return step;
                }
                for(int j = 0;j<4;j++){
                    for(int k = -1;k<2;k+=2){
                        auto next = node;
                        next[j]=(next[j]-'0'+k+10)%10+'0';
                        q.push(next);
                    }
                }
                visited.insert(node);
            }
            step++;
            
            
        }
        return -1;
    }
//     void bfs(){
//         queue<int>q;
//         q.push();
//         while(){
            
//         }
//     }
};
