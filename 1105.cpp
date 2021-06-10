class Solution {
public:
    int memo[1001][1001] = {0};
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        return dfs(books,0,shelf_width,0,shelf_width);

    }
    //对于每一本书 要么放到当前层 要么开始新的一层
    int dfs(vector<vector<int>>& b,int index,int remain_w,int h, int shelf_width){
        if(index>=b.size())return h;
        if(memo[index][remain_w]!=0)return memo[index][remain_w];
        int cur_w=b[index][0];
        int cur_h=b[index][1];
        int cur_layer=INT_MAX;
        if(remain_w>=cur_w)
        cur_layer=dfs(b,index+1,remain_w-cur_w,max(h,cur_h),shelf_width);
        int next_layer=h+dfs(b,index+1,shelf_width-cur_w,cur_h,shelf_width);

        return memo[index][remain_w]=min(cur_layer,next_layer);

    }
};
