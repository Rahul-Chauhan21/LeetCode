//Day 2
/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:

Input: J = "z", S = "ZZ"
Output: 0

Note:

    S and J will consist of letters and have length at most 50.
    The characters in J are distinct.


*/
class Solution {
public:
    //O(M + N) O(M)
    int numJewelsInStones(string J,string S){
        unordered_set<char> jewels;
        int numJewels = 0;
        for(char j: J){
            if(jewels.find(j) == jewels.end()){
                jewels.insert(j);
            }
        }

        for(char s: S){
            if(jewels.find(s) != jewels.end()){
                numJewels++;
            }
        }
        return numJewels;
    }

    /*
        unordered_map<char,int> jewels;
        for(int i = 0; J[i] != '\0'; i++){
            jewels[J[i]]++;
        }

        int count = 0;
        for(char c : S){
            if(jewels.find(c) != jewels.end()){
                count++;
            }
            return count;
        }
    */
};
