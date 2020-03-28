// https://leetcode-cn.com/problems/longest-word-in-dictionary/submissions/
// 非Trie解法
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        set<string> s;
        string res = words[0];
        for (auto&& word: words) {
            if (word.size() == 1 || s.find(word.substr(0, word.size()-1)) != s.end()) {
                if (word.size() > res.size()) {
                    res = word;
                }
                s.insert(word);
            }
        }
        return res;
    }
};
