# Time Complexity: O(N)
# Space Complexity: O(N)

from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        m = defaultdict(list)
        for s in strs:
            x = ''.join(sorted(s))
            m[x].append(s)
        for k, v in m.items():
            ans.append(v)
        return ans
