class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = adjacent_find(nums.begin(), nums.end());
        return *it;
    }
};