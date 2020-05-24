//Day 2
/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example:

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1


*/
class Solution {

    public:

    int squareSum(int n){
        int sum = 0;
            while(n){
                int digit = n%10;
                n/=10;
                sum+=digit*digit;
            }
        return sum;
    }
    //O(1) time
    bool isHappy(int n) {
        unordered_set<int>visted;

            while(true){
                if(n==1)
                    return true;
                n = squareSum(n);
                if(visted.count(n)==1)
                    return false;
                visted.insert(n);
            }
    }
};
