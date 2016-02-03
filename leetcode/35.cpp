class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        return distance(nums.begin(), it);
    }
};