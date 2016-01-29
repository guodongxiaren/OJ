class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator it = remove(nums.begin(), nums.end(), 0);
        for (; it != nums.end(); it++) {
            *it = 0;
        }
        
    }
};