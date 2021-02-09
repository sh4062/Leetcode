class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        vector<int>st;
        //哨兵 用于出入
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for(int i = 0;i<heights.size();i++){
            while(st.size()>0&&heights[i]<heights[st[st.size()-1]]){
                int cur = st.back();
                st.pop_back();
                int left_index = st.back()+1;
                int right_index = i;
                //cout<<i<<" "<<left_index<<" "<<heights[cur]<<endl;
                res=max(res,int((right_index-left_index))*heights[cur]);
            }
            
            st.push_back(i);
            
        }
        return res;

    }
};
