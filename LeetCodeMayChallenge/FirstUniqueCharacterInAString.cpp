//Day 5
/*
 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
*/
class Solution {
public:
    int firstUniqChar(string s) {

        if(s == "") return -1;
        vector<int> letterCount(26,0);

            for(char c : s){
                letterCount[c - 'a']++;
            }

            for(int i = 0; i < s.length(); i++){
                char c = s[i];
                if(letterCount[c-'a'] == 1){
                    return i;
                }
            }
        return -1;
    }
};
