class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int>res;
        int n = encoded.size()+1;
        int all=0;
        for(int i =1;i<=n;i++){
           all^=i;
        }
        int even=0;
        for(int i =1;i<n;i+=2){
           even^=encoded[i];
        }
        int first = all^even;
        res.push_back(first);
        for(int i = 1;i<n;i++){
            res.push_back(encoded[i-1]^res[i-1]);
        }
        return res;

    }
};
