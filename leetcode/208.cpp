// https://leetcode-cn.com/problems/implement-trie-prefix-tree/
class Trie {
public:
    bool is_word = false;
    Trie* next[26] = {0};
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* p = this;
        for (char ch: word) {
            int index = ch - 'a';
            if (!p->next[index]) {
                p->next[index] = new Trie();
            }
            p = p->next[index];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* p = this;
        for (char ch: word) {
            int index = ch - 'a';
            if (!p->next[index]) {
                return false;
            }
            p = p->next[index];
        }
        return p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* p = this;
        for (char ch: prefix) {
            int index = ch - 'a';
            if (!p->next[index]) {
                return false;
            }
            p = p->next[index];
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
