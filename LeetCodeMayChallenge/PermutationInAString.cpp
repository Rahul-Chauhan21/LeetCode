//Day 18
/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.



Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False



Note:

    The input strings only contain lower case letters.
    The length of both given strings is in range [1, 10,000].


*/
//Permutation of a string is also anagram
class Solution {
public:
    //O(AlphabetSize*Length(S2)) time | O(AlphabetSize) space
    bool checkInclusion(string s1, string s2) {
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);

        int window = s1.length();
        int len = s2.length();

        if(len < window){
            return false;
        }

        int left = 0, right = 0;
        //populate hash
        while(right < window){
            s1hash[s1[right] - 'a'] += 1;
            s2hash[s2[right++] - 'a'] += 1;
        }
        right -= 1;
        // using sliding window technique while sliding one character at a time and keep updating the hash
        // using left and right pointers to keep track of boundary elements of a window
        while(right < len){
            if(s1hash == s2hash){
                return true;
            }
            right += 1;
            if(right != len){
                s2hash[s2[right] - 'a'] +=1;
            }
            s2hash[s2[left] - 'a'] -= 1;
            left += 1;
        }
        // sliding through entire string we couldn't find the two hashes being same.
        return false;
    }
};
