class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        has = set()
        lacking = set()
        count = 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                if s1[i] in lacking:
                    lacking.remove(s1[i])
                else:
                    lacking.add(s2[i])
                if s2[i] in has:
                    has.remove(s2[i])
                else:
                    has.add(s1[i])
                count += 1        
        if (len(has) > 0 or len(lacking) > 0):
            return False
        if count == 0 or count == 2:
            return True
        return False