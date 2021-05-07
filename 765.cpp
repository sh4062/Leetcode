class Solution {
public:

    int minSwapsCouples(vector<int>& row) {
        
        int res = 0;
        for(int i=0;i<row.size();i+=2){
            
            if(row[i]%2==0){
            if(row[i+1]-row[i]==1)continue;
            for(int j = i+2;j<row.size();j++){
                if(row[j]==row[i]+1){
                    swap(row[j],row[i+1]);
                    res++;
                }
            }
            }else{
                if(row[i]-row[i+1]==1)continue;
                for(int j = i+2;j<row.size();j++){
                 if(row[j]==row[i]-1){
                    //cout<<row[j]<<endl;
                    swap(row[j],row[i+1]);
                    res++;
                }
            }

            }
        }


        return res;

    }
};
