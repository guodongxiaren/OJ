// https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/submissions/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size() -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] <= A[mid+1]) {
                left = mid+1;
            } else if (A[mid-1] <= A[mid]){
                return mid;
            } else {
                right = mid-1;
            }
        }
        return -1;
    }
};
