// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first = 1, last = n;
        while (first < last)
        {
            int mid = first + (last - first)/2;  // 为什么 mid = (last + first)/2; 超时
            if (isBadVersion(mid))
            {
                last = mid;
            }
            else
            {
                first = mid + 1;
            }
        }
        return first;
    }
};
