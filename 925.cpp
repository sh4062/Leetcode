class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        if(name[0]!=typed[0])return false;
        int cnt1=0,cnt2=0;
        while(i<name.size()&&j<typed.size()){
            if(name[i]==typed[j]){
                i++;
                j++;
            }
            else if((name[i]!=typed[j])&&typed[j]==typed[j-1]){
                j++;
            }else{
                return false;
            }
        }
        while(j<typed.size()){
            if(typed[j]==typed[j-1])j++;
            else break;
        }
        // cout<<i<<endl;
        // cout<<j<<endl;
        if(i==name.size()&&j==typed.size())
        return true;
        else return false;

    }
};
