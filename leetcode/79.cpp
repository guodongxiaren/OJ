//https://leetcode.com/problems/word-search/description/
class Solution {
public:
    
    bool exist(vector<vector<char>>& board, string word, int i, int j) {
        int y_len = board.size();
        int x_len = board[0].size();
        if (i < 0 || i >= y_len || j < 0 || j >= x_len) {
            return false;
        }
        if (board[i][j] != word[0]) {
            return false;
        }
        // board[i][j] == word[0]
        if (word.size() == 1) {
            return true;
        }
        board[i][j] = 0;
        bool right_flag = exist(board, word.substr(1), i, j + 1);
        bool left_flag = exist(board, word.substr(1), i, j - 1);
        bool down_flag = exist(board, word.substr(1), i + 1, j);
        bool up_flag = exist(board, word.substr(1), i - 1, j);
        if (right_flag| left_flag| down_flag| up_flag) {
            return true;
        } else {
            board[i][j] = word[0];
            return false;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int y_len = board.size();
        int x_len = board[0].size();
        
        
        for (int i = 0; i < y_len; ++i) {
            for (int j = 0; j < x_len; ++j) {
                if (board[i][j] == word[0] && exist(board, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
