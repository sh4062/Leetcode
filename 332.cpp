class Solution {
public:
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> s;
        s.push_back("JFK");
        vector<int>visited(tickets.size(),0);
        sort(tickets.begin(),tickets.end());//!!!
        backtrace(tickets,s,visited);
        return res;

    }
    bool backtrace(vector<vector<string>>& tickets,vector<string>& s,vector<int>&visited){
        if(s.size()==tickets.size()+1){
            //cout<<s.size();
            //if(res.size()==0)
            res=s;
            // else res=min(res,s);
            //cout<<res[1]<<endl;
            return true;
        }
        //cout<<s[s.size()-1]<<endl;
        for(int i = 0;i<tickets.size();i++){
             int n =s.size();
             if(visited[i]==1||tickets[i][0]!=s[n-1])continue;
             s.push_back(tickets[i][1]);
             visited[i]=1;
             if(backtrace(tickets,s,visited))return true;
             visited[i]=0;
             s.pop_back();
        }
        return false;

    }
};
