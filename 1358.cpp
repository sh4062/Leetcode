class Solution {
public:
    bool valid(string a,int st,int ed){
        int a1 = 0,a2=0,a3=0;
        for(int i = st;i<=ed;i++){
            if(a[i]=='a')a1++;
            if(a[i]=='b')a2++;
            if(a[i]=='c')a3++;
            if(a1&&a2&&a3)break;
        }
        return a1&&a2&&a3;
        
    }
    int hashmap[3] = {0,0,0}; 
    int numberOfSubstrings(string s) {
        int left = 0,right = -1;
        int n = s.size();
        int cnt = 0;
        while(right<n-1){
            hashmap[s[++right]-'a']++;
            
           
            while((hashmap[0]&&hashmap[1]&&hashmap[2])){
                //cout<<left<<":"<<right<<endl;
                cnt+=n-right;
                hashmap[s[left]-'a']--;
                left++;
                
                
            }
            
        }
        return cnt;


    }
};
