class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        if s == t:
            return True
        ss = list(s)
        ss.sort()
        tt = list(t)
        tt.sort()
        return ss == tt
