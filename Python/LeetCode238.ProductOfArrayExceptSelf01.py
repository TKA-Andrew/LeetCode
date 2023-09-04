# Time Complexity: O(N)
# Space Complexity: O(N)

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        N = len(nums)
        pre_product = [1 for i in range(N)]
        post_product = [1 for i in range(N)]

        for i in range(1, N):
            pre_product[i] = pre_product[i-1] * nums[i-1]

        for i in range(N - 2, -1, -1):
            post_product[i] = post_product[i+1] * nums[i+1]

        for i in range(N):
            nums[i] = pre_product[i] * post_product[i]

        return nums
