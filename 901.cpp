class StockSpanner {
public:
    // stack<int>st;
    vector<int>v;
    StockSpanner() {

    }
    
    int next(int price) {\
        int res = 0;
         v.push_back(price);
        //while(!st.empty())st.pop();
        for(int i = v.size()-1;i>=0;i--){
            // while(!st.empty()&&v[i]<v[st.top()]){
                
            //     st.pop();
            // }
            // st.push(i);
            if(v[i]>price)break;
            res++;
        }
       
        return res;

    }
};
