class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        t = s.split()
        t.reverse()
        return " ".join(t)

"""
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
"""
