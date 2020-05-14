//Day 13
/*
Given a non-negative integer num represented as a string, remove k digits from the number so that
the new number is the smallest possible.

Note:

    The length of num is less than 10002 and will be ≥ k.
    The given num does not contain any leading zero.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain
leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = num.size();
        stack<char> st;
            //store the final string
            //O(N) O(N)
            for(char c : num){
                while(!st.empty() && k > 0 && st.top() > c){//maxima arises in the curve; remove it.
                    st.pop();
                    k-=1;
                }
                if(!st.empty() || c!='0'){
                    st.push(c);
                }
            }
            //remove largest values from stack
            while(!st.empty() && k--){ // if the number is in increasing order
                st.pop();
            }
            if(st.empty()){
                return "0";
            }
            //retrieve number the from stack into the string; reusing num.
            while(!st.empty()){
                num[n-1] = st.top();
                st.pop();
                n-=1;
            }
        return num.substr(n);
    }
};
