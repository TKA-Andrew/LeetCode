class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dicts = {}
        dictt = {}

        for c in s:
            dicts[c] = dicts.get(c, 0) + 1
        for c in t:
            dictt[c] = dictt.get(c, 0) + 1
        return dicts == dictt