class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, length = nums.size();
        int left = 0, right = 0, flag = 0;

        while (right < length) {
            // 统计0出现的次数
            if (nums[right] == 0) {
                flag++;
            }
            // 移动右指针
            right++;

            // 如果窗口出现了两个0, 移除第一个出现的0
            while (flag > 1) {
                if (nums[left] == 0) {
                    flag--;
                }
                // 移动左指针, 缩小窗口
                left++;
            }
            // 因为是移除一个元素, 所以计算的时候就是 right - left - 1, -1 就是把那个元素移除掉
            res = max(res, right - left - 1);
        }

        return res;


    }
};
