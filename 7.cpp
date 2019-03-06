class Solution {
public:
    int reverse(int x) {
        const int R = 10;
        
        if (x == INT_MIN) {
            return 0;
        }
        
        if (x < 0) {
            return -reverse(-x);
        }
        int64_t res = 0;
        while (x > 0) {
            res = res * R + x % R;
            if (res > INT_MAX) {
                return 0;
            }
            x /= R;
        }
        return res;
    }
};

// class Solution {
// public:
//     int reverse(int x) {
//         int flag = 1;
//         if (x == INT_MIN) {
//             return 0;
//         }
//         if(x<0) {flag = -1;x= -x;}
//         long int rev = 0;
//         while(x){
//             rev = rev*10+x%10;
//             if (rev > INT_MAX) {
//                 return 0;
//             }
//             x=x/10;
//         }
//         return flag*rev;
        
        
//     }
// };