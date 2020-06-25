/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


*/
class Solution {
public:
    //O(n) time | O (min(m,n)) where m is the size of hashMap
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int startIdx = 0, maxLen = 0;

            for(int i = 0; i < s.length(); i++){
                char character = s[i];
                if(lastSeen.find(character) != lastSeen.end()){
                    startIdx = max(startIdx, lastSeen[character] + 1);
                }
                maxLen = max(maxLen, i + 1 - startIdx);
                lastSeen[character] = i;
            }
        return maxLen;
    }
};
