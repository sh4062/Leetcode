/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
#include <limits>
class Solution {
public:
    long int guessNumber(long int n) {
        long int low = 1, high = INT_MAX;
        if(guess(n)<0)high = n;
        else if(guess(n)>0)low = n;
        else return n;
        while(low!=high){
            long int mid = (low+high)/2;
            //cout<<low<<endl;
            if(guess(mid)<0)high = mid;
            else if(guess(mid)>0)low = mid;
            else return mid;
        }
        
        return n;
    }
};