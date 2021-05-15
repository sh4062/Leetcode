class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        for(int i = 31;i>=0;i--){
            mask = mask|(1<<i);
            
            unordered_set<int>s;
            for(auto n:nums){
                s.insert(n&mask);
            }
            //假设最大值 高位1^高位0=结果 结果^高位0=高位1
            int tmp = res | (1<<i);
            for (auto t:s)
                if (s.count(tmp ^ t)){
                    res = tmp;
                    break;
                    }
                    

        }
        return res;

    }
};
