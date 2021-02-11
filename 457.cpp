class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            //for(int j = i+1;j<nums.size();j++){
                int flag = nums[i]>0?1:-1;
                int l = 1;
                   
                
                int s = i;
                int j =s + nums[s];
                cout<<j<<endl;
                if(j>=int(nums.size()))
                    j=j-j/nums.size()*nums.size();
                cout<<j<<endl;
                while(j<0)
                    j=j+(nums.size());
                //cout<<j<<endl;
                while(j!=i){
                    
                    s=j;
                    if(nums[j]<0&&flag>0){
                        l=nums.size()+1;
                        break;
                    }
                    if(nums[j]>0&&flag<0){
                        l=nums.size()+1;
                        break;
                    }
                    j=j + nums[j];
                    if(j>=int(nums.size()))
                    j=j-j/nums.size()*nums.size();
                    while(j<0)
                    j=j+(nums.size());
                    //s=j;
                    //cout<<j<<endl;
                    l++;
                    if(l>nums.size())break;
                
                
                }
                //cout<<l<<endl;
                if(l>1&&l<=nums.size())return true;
                
                

            //}
        }
        
        return false;

    }
};
