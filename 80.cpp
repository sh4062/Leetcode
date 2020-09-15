class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int res=nums.size();
        if(nums.size()<2){return res;}
        int c = 0;
        if(nums[0]==nums[1])c++;
        
        for(vector<int>::iterator i=nums.begin()+1;i<nums.end();i++){
            index++;
            if(*i==*(i-1))
            {
                c++;
            }
            else{
                if(c>=3){
                    nums.erase(i-(c-2),i);
                    res-=c-2;
                    i-=c-2;
                }
                
                c=1;
            }
            //cout<<*i;
            if(i==nums.end()-1){
                if(c>=3){
                    nums.erase(i-(c-2),i);
                    res-=c-2;
                }
                
            }
            
            
        }
        return res;
    }
};
