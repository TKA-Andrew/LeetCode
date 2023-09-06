# Time Complexity: O(N)
# Space Complexity: O(N)

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()

        for i, a in enumerate(nums):
            if i > 0 and nums[i-1] == a:
                continue

            L = i + 1
            R = len(nums) - 1
            while L < R:
                total = a + nums[L] + nums[R]
                if total == 0:
                    ans.append([a, nums[L], nums[R]])
                    L += 1
                    while L < R and nums[L] == nums[L-1]:
                        L += 1
                elif total > 0:
                    R -= 1
                else:
                    L += 1

        return ans
