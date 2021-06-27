class Solution {
public:
    int res=0;
    // void dfs(vector<int>& h,int index,int b,int l){
    //     res=max(res,index);
    //     if(index>=h.size()-1) return;
    //     if(h[index]>=h[index+1]){
    //         dfs(h,index+1,b,l);
    //         return;
    //     }else{
    //         //梯子
    //         if(l<=0&&b<h[index+1]-h[index])return;
            
    //         if(b>=h[index+1]-h[index]){
    //             dfs(h,index+1,b-(h[index+1]-h[index]),l);
    //         }
    //         if(l>=1)
    //         dfs(h,index+1,b,l-1);
            
    //     }
    // }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int cur = heights[0];
        int b = 0;
        priority_queue<int,vector<int>,less<int>>q;
        if(heights.size()<2)return 0;
        int i = 1;
         for(i;i<heights.size();i++){
             if(heights[i]<=cur){
                 cur=heights[i];
             }else{
                 
                 q.push(heights[i]-cur);
                 b+=heights[i]-cur;
                 while(b>bricks&&ladders>0){
                     int tmp = q.top();
                     //cout<<tmp<<endl;
                     q.pop();
                     b-=tmp;
                     ladders--;
                 }
                 if(b>bricks&&ladders<=0)break;
                 else if(b>bricks&&ladders>0){
                     ladders--;
                     cur=heights[i];
                     continue;

                 }
                 cur=heights[i];
             }
         }
        //cout<<i-1;
        //dfs(heights,0,bricks,ladders);
        return i-1;


    }
};
