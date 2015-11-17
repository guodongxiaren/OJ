class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 0:
            return False
        else:
            return n & (n - 1) == 0
"""
if n is power of 2
then n & (n -1) == 0
"""
