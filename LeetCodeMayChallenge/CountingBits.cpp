//Day 28
/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]

Example 2:

Input: 5
Output: [0,1,1,2,1,2]

*/
class Solution {
public:
    /*
     compute the current ith set bit counts by using the previous count at i/2 in O(1) time
    */
    //O(n) time | O(n) space where n is the range from 0 to num
    vector<int> countBits(int num) {
        vector<int> mem(num+1);
        mem[0] = 0;
            for(int i = 1; i <= num; i++){
                mem[i] = mem[i/2] + i%2; // if odd lsb has 1 else in case of even lsb is 0
            }
        return mem;
    }
};
