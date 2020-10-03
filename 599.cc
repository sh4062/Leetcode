class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>m1;
        unordered_map<string,int>m2;
        unordered_map<string,int>m3;
        for(int i=0;i<list1.size() ;i++){
            m1[list1[i]]+=i;
        }
        for(int i=0;i<list2.size() ;i++){
            m2[list2[i]]+=i;
        }
        vector<string> res;
        int minI=INT_MAX;
        
        for(auto i:m1){
            if(m2.find(i.first)!=m2.end()){
                int sum_=i.second+m2[i.first];
                minI=min(minI,sum_);
                m3[i.first]=sum_;
            }
        }
        for(auto i:m3){
            if(i.second==minI){
                res.push_back(i.first);
            }
        }
        return res;
    }
};
