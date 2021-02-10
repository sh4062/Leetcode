class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    std::queue<int> q; //存储到目前为止入度为0的点
    std::vector<int> ans; //储存答案
    vector<int>in(numCourses,0);
    vector<int>visited(numCourses,0);
    for(auto i:prerequisites){
        in[i[0]]++;

    }
    for (int i = 0; i < numCourses; i++) {
        if(!in[i]){ q.push(i); //如果入度为0则加入队列中
        visited[i]++;}
    }
    
    while(!q.empty()) { //简单的搜索
        int t = q.front(); q.pop();
        
        ans.push_back(t);
        for (int i = 0; i<prerequisites.size(); i++) {
            if(prerequisites[i][1]==t)
            in[prerequisites[i][0]]--;
           
        }
        for (int i = 0; i<numCourses; i++) {
         if(in[i]==0&&visited[i]==0){
            q.push(i);
            visited[i]++;
            }
        }
    }
    return ans.size()==numCourses?ans:vector<int>{} ;

    }
//     void toposort() {
   
    
//     for (int i = 0; i < n; i++) { //查看拓扑排序后的数组
//         printf("%d\n", ans[i]);
//     } return ;
// }
};
