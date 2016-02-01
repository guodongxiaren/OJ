class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        typedef vector<int>::iterator iter;
        for (iter it = nums.begin(); it != nums.end(); ++it)
        {
            int x = target - *it;
            iter p = find(it+1, nums.end(), x);
            if (p != nums.end())
            {
                int i = distance(nums.begin(), it)+1;
                int j = distance(nums.begin(),  p)+1;
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
        return res;
    }
};