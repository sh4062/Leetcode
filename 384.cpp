class Solution {
public:
    vector<int> tmp1;
    vector<int> tmp2;
    Solution(vector<int>& nums):tmp1(nums),tmp2(nums) {
 
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return tmp1;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = tmp2.size()-1;i>=1;i--){
            swap(tmp2[i],tmp2[rand()%(tmp1.size()-1)]);
        }
        return tmp2;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
