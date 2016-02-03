// lower_bound upper_bound
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        typedef vector<int>::iterator iter;
        vector<int> res;
        
        iter first = lower_bound(nums.begin(), nums.end(), target);
        if (first == nums.end() || *first != target)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(distance(nums.begin(), first));
        iter second = upper_bound(first, nums.end(), target);
        res.push_back(distance(nums.begin(), second)-1);
        return res;
    }
};

// equal_range
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        typedef vector<int>::iterator iter;
        vector<int> res;
        pair<iter, iter> bound = equal_range(nums.begin(), nums.end(), target);
        iter first  = bound.first;
        iter second = bound.second;
        if (first == nums.end() || *first != target)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(distance(nums.begin(), first));
        res.push_back(distance(nums.begin(), second)-1);
        return res;
    }
};