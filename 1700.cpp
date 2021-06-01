class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        for(auto s:students)q.push(s);
        int index = 0;
        int cur = 0;
        while(1){
            int flag = 0;
            for(int i = q.size();i>0;i--){
            auto tmp = q.front();
            q.pop();
            if(tmp==sandwiches[index]){
                index++;
                flag=1;
            }else{
                q.push(tmp);
            }
            }
            if(flag==0)break;
        }




        return sandwiches.size()-index;

    }
};
