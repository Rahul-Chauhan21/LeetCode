//Day 9
/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true

Example 2:

Input: 14
Output: false


*/
#define ll long long
class Solution {

public:
    bool isPerfectSquare(int num) {
        //O(log sqrt(N))
        ll high = 100000;
        ll low = 0;
        ll sq,mid;

        while(low <= high){
            mid = low + (high - low)/2;
            sq = mid * mid;
            if(sq == num) return true;

            else if(sq < num){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }

        }
        return false;
    }
};
