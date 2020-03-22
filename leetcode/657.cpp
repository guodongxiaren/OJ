// https://leetcode-cn.com/problems/robot-return-to-origin/
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (auto& m: moves) {
            if (m == 'R') {
                x++;
            }
            if (m == 'L') {
                x--;
            }
            if (m == 'U') {
                y++;
            }
            if (m == 'D') {
                y--;
            }
        }
        if (!x && !y) {
            return true;
        } else {
            return false;
        }
    }
};
