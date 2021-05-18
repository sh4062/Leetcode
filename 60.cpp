class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v(n,0);
        for(int i = 1;i<=n;i++){
            v[i-1]=i;
        }
        k-=1;
        while(next_permutation(v.begin(),v.end())&&--k){
                   
        }
        string s;
        for(auto i:v)s+=to_string(i);
        return s;
    }
};
