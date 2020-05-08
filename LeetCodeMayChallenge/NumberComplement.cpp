//Day 4
/*
Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.



Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bit), and its complement is 0. So you need to output 0.
*/

class Solution {
public:
    int findComplement(int num) {
        /*if(num == 0) return 1;
        int num_bits = log2(num) + 1;
        int mask = (unsigned)(1 << num_bits) - 1; //since we always aquired an extra bit to find the mask.
        // to keep the mask in the positive range of signed integer.
        return num ^ mask;*/

        //O(1) time
        int res = 0, i = 0;
        while(num){
            if((num&1) == 0){ //for every num we check if lsb is unset.
                res += (1 << i);
            }

            i++;
            num>>=1;
        }

        return res;
    }
};
