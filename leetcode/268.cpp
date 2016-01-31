struct OP {
    bool operator() (int& i) {
        base++;
        return base != i;
    }   
    int base;
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        OP op;
        op.base = 0;
        sort(nums.begin(), nums.end());
        if (0 != nums[0])
        {
            return 0;
        }
        
        vector<int>::iterator it = find_if(nums.begin() + 1, nums.end(), op);
        if (nums.end() == it) 
        {
            return *(--it) + 1;
        }
        return *it - 1;
    }
};