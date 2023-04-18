class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        N = len(s)
        M = len(t)

        if N == 0: return True

        i = 0
        j = 0

        while j < M and i < N:
            if s[i] == t[j]:
                j += 1
                i += 1
            else:
                j += 1
            
        return i == N