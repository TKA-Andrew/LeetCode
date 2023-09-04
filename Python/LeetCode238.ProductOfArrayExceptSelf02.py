# Time Complexity: O(N)
# Space Complexity: O(1)


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        N = len(nums)
        res = [1 for i in range(N)]
        pre = 1
        post = 1

        for i in range(N):
            res[i] = pre
            pre = nums[i] * pre

        for i in range(N-1, -1, -1):
            res[i] = post * res[i]
            post = nums[i] * post

        return res
