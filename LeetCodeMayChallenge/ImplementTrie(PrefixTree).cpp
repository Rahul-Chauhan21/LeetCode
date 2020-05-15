//Day 14
/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true

Note:

    You may assume that all inputs are consist of lowercase letters a-z.
    All inputs are guaranteed to be non-empty strings.


*/

class TrieNode{
  public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        this->root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) { // O(L) L is the length of longest string inserted
        TrieNode* node = this->root;
            for(int i = 0; i < word.length(); i++){
                char letter = word[i];
                if(node->children[letter-'a'] == NULL){
                    node->children[letter-'a'] = new TrieNode();
                }
                node = node->children[letter-'a'];
            }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {//O(Length of searched string)
        TrieNode* node = this->root;
            for(char c : word){
                if(node->children[c-'a'] == NULL){
                    return false;
                }
                node = node->children[c-'a'];
            }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {//O(Length of searched string)
        TrieNode* node = this->root;
            for(char c : prefix){
                if(node->children[c-'a'] == NULL){
                    return false;
                }
                node = node->children[c-'a'];
            }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
