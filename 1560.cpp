class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int>res;
        vector<int>aux(n+1,0);
        int s  = rounds[0];
        aux[s]++;
        for(int i = 1;i<rounds.size();i++){
            while(s!=rounds[i]){
                s++;
                if(s>n)s=s%n;
                aux[s]++;
            }

        }
        int maxn=*max_element(aux.begin(),aux.end());
        for(int i = 1;i<aux.size();i++){
            if(aux[i]==maxn)
            res.push_back(i);

        }
        return res;

    }
};
