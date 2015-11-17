class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.insert(0, float('-Inf'))
        nums.append(float('-Inf'))
        for i in range(len(nums))[1:-1]:
            if nums[i] > nums[i-1] and nums[i] > nums[i+1]:
                return i - 1
