/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...

Example 1:

Input: "A"
Output: 1

Example 2:

Input: "AB"
Output: 28

Example 3:

Input: "ZY"
Output: 701

*/
class Solution {
public:
    int titleToNumber(string s) {
        //Right to left
        /*int j = 0;
        int ans = 0;
            for(int i = s.length() - 1; i >= 0; i--){
                ans += pow(26, j) * (s[i] - 'A' + 1);
                j++;
            }
        return ans;
        */

        //Left to Right
        //O(N) time | O(1) space
        int result = 0;
        int n = s.length();
            for(int i = 0; i < n; i++){
                result = result * 26;
                result += (s[i] - 'A' + 1);
            }
        return result;
    }
};
