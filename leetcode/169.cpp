class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        return nums[size/2];
    }
};