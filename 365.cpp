class Solution {
public:
struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

    bool canMeasureWater(int x, int y, int z) {
        //可以用bfs枚举状态
        if(z==0)return true;
        if(z>x+y)return false;
        queue<pair<int,int>>q;
        unordered_set<pair<int,int>,pair_hash>st;
        q.push({0,0});
        st.insert({0,0});
        
        while(!q.empty()){
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            if(curX+curY==z||curX==z||curY==z){
                return true;
            }
            //加满
            if(st.find({curX,y})==st.end()){
                st.insert({curX,y});
                q.push({curX,y});
            }
            if(st.find({x,curY})==st.end()){
                st.insert({x,curY});
                q.push({x,curY});
            }
            //倒空
            if(st.find({curX,0})==st.end()){
                st.insert({curX,0});
                q.push({curX,0});
            }
            if(st.find({0,curY})==st.end()){
                st.insert({0,curY});
                q.push({0,curY});
            }
            //相互倒
            //x->y
            if(curX+curY>=y){
                if(st.find({curX + curY - y, y})==st.end()){
                st.insert({curX + curY - y, y});
                q.push({curX + curY - y, y});
            }

            }else{
                if(st.find({0,curX+curY})==st.end()){
                st.insert({0,curX+curY});
                q.push({0,curX+curY});
            }

            }
            //y->x
            if(curX+curY>=x){
                if(st.find({x,curX+curY-x})==st.end()){
                st.insert({x,curX+curY-x});
                q.push({x,curX+curY-x});
            }

            }else{
                if(st.find({curX+curY,0})==st.end()){
                st.insert({curX+curY,0});
                q.push({curX+curY,0});
            }
                
            }



        }



        return false;


    }
};
