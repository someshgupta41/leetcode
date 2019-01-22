class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        if(len(s) == 0):
            return 0
        rs1 = s.rstrip()
        s1 = rs1.rsplit(' ')
        return (len(s1[len(s1) -1]))