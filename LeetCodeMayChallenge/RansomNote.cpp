//Day 3
/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:

    You may assume that both strings contain only lowercase letters.

*/

class Solution {
public:
    //O(N + M)
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> magazineHash(26,0);

            for(int i = 0; magazine[i]!='\0'; i++)
                magazineHash[magazine[i] - 'a'] +=1;

            for(int i = 0; ransomNote[i]!='\0'; i++){
                if(magazineHash[ransomNote[i] - 'a'] == 0){
                    return false;
                }
                else{
                    magazineHash[ransomNote[i]-'a']-=1;
                }
            }
        return true;
    }
};

