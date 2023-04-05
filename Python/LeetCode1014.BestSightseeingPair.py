class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        # values[i] +  values[j] + i - j
        # can be expressed as 
        # values[i] +  (values[j] + i - j)
        # To maximum cur avaiable
        # 
        ans = 0
        cur = 0

        for v in values:
            ans = max(ans, cur + v) # maximum values[i]
            cur = max(cur, v) - 1 # maximum values[j] + i - j
        return ans
