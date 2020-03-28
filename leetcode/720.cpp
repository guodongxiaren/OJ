// https://leetcode-cn.com/problems/longest-word-in-dictionary/submissions/
// Trie前缀树解法
class Solution {
public:
    struct Node {
        bool end = false;
        Node* next[26] = {0};
    };
    void insert(Node* root, const string& word) {
        Node* node = root;
        for (char c: word) {
            int i = c - 'a';
            if (!node->next[i]) {
                node->next[i] = new Node;
            } 

            node = node->next[i];
        }
        node->end = true; // is a word
    }
    bool search(Node* root, const string& word) {
        Node* node = root;
        int i = -1;
        for (char c: word) {
            i = c - 'a';
            if (!node->next[i]) {
                return false;
            }
            node = node->next[i];
            if (node->end == false) {
                return false;
            }
        }
        return true;
    }
    string longestWord(vector<string>& words) {
        Node* root = new Node;
        for (auto&& word: words) {
            insert(root, word);
        }
        string res = "";
        for (auto&& word: words) {
            if (!search(root, word)) {
                continue;
            }
            if (res == "" || word.size() > res.size() 
                    || (word.size() == res.size() && word < res)) {
                res = word;
            }
        }
        return res;
    }
};
