class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        typedef vector<int>::reverse_iterator iter;
        int e = 1;
        for (iter it = digits.rbegin(); it != digits.rend(); ++it) {
            int i = *it;
            i += e;
            if (i == 10) {
                res.push_back(0);
                e = 1;
                continue;
            }
            res.push_back(i);
            e = 0;
        }
        if (e == 1) {
            res.push_back(1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};