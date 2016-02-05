class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size()) {
            k %= nums.size();
        }
        std::rotate(nums.begin(), nums.end()-k, nums.end());
    }
};