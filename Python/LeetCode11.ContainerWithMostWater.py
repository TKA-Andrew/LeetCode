# Time Complexity: O(N)
# Space Complexity: O(1)

class Solution:
    def maxArea(self, height: List[int]) -> int:
        N = len(height)
        left = 0
        right = N - 1
        maxArea = 0

        while left < right:
            minH = min(height[left], height[right])
            area = minH * (right - left)
            maxArea = max(area, maxArea)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return maxArea
