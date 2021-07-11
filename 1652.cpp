class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>v(n,0);
        if(k==0)return v;
        if(k>0){
        for(int i = 0;i<n;i++){
            int tmp = 0;
             for(int j = i+1;j<=i+k;j++){
                   tmp+=code[j%n];
             }
             v[i]=tmp;
        }
        }else{for(int i = 0;i<n;i++){
            int tmp = 0;
             for(int j = i-1;j>=i-(-k);j--){
                   tmp+=code[(j+n)%n];
                   //cout<<tmp<<endl;
             }
             v[i]=tmp;
        }

        }
return v;

    }
};
