bool isPositive(int i) {
    return i>0;
}
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unique(nums.begin(), nums.end());
        vector<int>::iterator it = find_if(nums.begin(), nums.end(), isPositive);
        if (nums.end() == it)
        {
            return 1;
        }
        
        int base = 0;
        for (; it != nums.end(); ++it)
        {
            base++;
            if (*it != base)
            {
                break;
            }
        }
        if (it == nums.end())
        {
            return base+1;
        }
        return base;
    }
};