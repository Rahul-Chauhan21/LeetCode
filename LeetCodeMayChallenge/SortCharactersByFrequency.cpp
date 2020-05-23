//Day 22
/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/
class Solution {
public:
    //O(122log122 + length(s)) time | O(alphabet_size) space
    string frequencySort(string s) {
        vector<pair<int,char>> hash('z'+1,{0,0});
        for(char c : s){
            hash[c] = {hash[c].first + 1, c}; //updating the hash table
        }

        sort(hash.begin(),hash.end());

        string res = "";

        for(auto p: hash){
            res = string(p.first,p.second) + res; // to avoid O(l1 + l2) time in string addition
        }

        return res;
    }
};
