class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>v={1,2,3,4,5,6,8,9,10,12};
        if(n<=v.size())return vector(v.begin(),v.end())[n-1];
        int v1=6,v2=4,v3=2;
        int m=INT_MAX;
        for(float i =0;i<n-10;i++){
            m=min(2*v[v1],min(3*v[v2],5*v[v3]));
            
            v.push_back(m);
            if(m==2*v[v1])v1++;
            if(m==3*v[v2])v2++;
            if(m==5*v[v3])v3++;

            
        }
        return v[n-1];
    }
};
