class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        N = len(nums)
        ans = []
        a = 0
        b = 0

        if N == 0:
            return []
        elif N == 1:
            return [str(nums[0])]

        while b+1 < N:
            if nums[b+1] - nums[b] > 1:
                if a == b:
                    ans.append(str(nums[a]))
                else:
                    ans.append(str(nums[a]) + "->" + str(nums[b]))
                a = b + 1
            b += 1
        
        if a == b:
            ans.append(str(nums[a]))
        else:
            ans.append(str(nums[a]) + "->" + str(nums[b]))

        return ans