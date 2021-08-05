class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
    int sum = 0;
    int cur = 1;
    for(cur;sum<target;cur++){
        sum+=cur;
    }
    cur--;
    if(sum==target)return cur;
    cout<<sum-target<<endl;
    while((target-sum)%2!=0){
        cur+=1;
        sum+=cur;
    }
    return cur;
    }
    

};
