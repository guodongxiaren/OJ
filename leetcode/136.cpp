struct OP {
    int operator() (int x, int y)
    {
        i*=-1;
        return x+i*y;
    }
    OP():i(-1){};
    int i;
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), 0, OP());
    }
};