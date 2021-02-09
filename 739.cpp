class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size()==0)return {};
        if(T.size()==1)return vector<int>{0};
        
        vector<int> st;
        T.insert(T.begin(),101);
        vector<int> res(T.size()-1,0);

        for(int i = T.size()-1;i>=0;i--){
            while(!st.empty()&&T[i]>=T[st.back()]){
                
                
                int cur_index=st.back();
                st.pop_back();
                //res[cur_index]=(st.back()-cur_index-1);
                if(!st.empty())
                res[cur_index-1]=(st.back()-cur_index);
                //cout<<st.back()-cur_index<<endl;
                else res[cur_index-1]=0;


            }
            st.push_back(i);
        }
        return res;


    }
};
