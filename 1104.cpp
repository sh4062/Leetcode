class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        if(label==1)return {1};
        int l = log2(label)+1;
        vector<int>res;
        vector<vector<int>> v(l+1);
        int start = 1;
        v[0].push_back(1);
        
        start++;
        for(int i = 1;i<=l;i++){
            if(i%2==0){
                for(int j = pow(2,i);j<pow(2,i+1);j++){
                    v[i].push_back(j);
                    // cout<<j<<endl;
                    if(j==label){
                        res.push_back(j);
                        int index = v[i].size()-1;
                        //cout<<index;
                        while(i){
                            i--;
                            index/=2;
                            res.push_back(v[i][index]);
                        }
                        reverse(res.begin(),res.end());
                        return res;

                    }
                    
                }

            }else{
                for(int j = pow(2,i+1)-1;j>=pow(2,i);j--){
                    v[i].push_back(j);
                    if(j==label){
                        res.push_back(j);
                        int index = v[i].size()-1;
                        //cout<<index;
                        while(i){
                            i--;
                            index/=2;
                            res.push_back(v[i][index]);
                        }
                        reverse(res.begin(),res.end());
                        return res;

                    }
                }
            }

        }
        
        return res;



    }
};
