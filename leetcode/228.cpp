class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (!nums.size())
        {
            return res;
        }
        
        int a = nums.front();
        int b = a;
        
        vector<int>::iterator it = nums.begin() + 1;
        for ( ; it != nums.end(); ++it)
        {
            if (*it == b + 1)
            {
                b++;
                continue;
            }
            ostringstream oss;
            if (a != b)
            {
                oss<<a<<"->"<<b;
            }
            else
            {
                oss<<a;
            }
            res.push_back(oss.str());
            a = b = *it;
        }
        ostringstream oss;
        if (a != b)
        {
            oss<<a<<"->"<<b;
        }
        else 
        {
            oss<<a;
        }
        res.push_back(oss.str());
        return res;
    }
};