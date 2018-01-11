/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        if(!id) return 0;
        int res = 0;
        int  i =0;
        for(i=0;i<employees.size();i++){
            if(employees[i]->id == id){
                break;
            }
        }
        Employee *p = employees[i];
        //cout<<(i)<<endl;
        queue<Employee*> q;
        q.push(p);
        while(!q.empty()){
            //cout<<(p->id)<<endl;
            p = q.front();
            q.pop();
            res = res + p->importance;
            if(p->subordinates.size()>0){
                for(i =0;i<p->subordinates.size();i++){
                    for(int j=0;j<employees.size();j++){
                          if(employees[j]->id == p->subordinates[i]){
                           q.push(employees[j]);
                    }
                   }
                   
                }
            }
        }
        
        
        
        
        
        
        return res;
    }
};
