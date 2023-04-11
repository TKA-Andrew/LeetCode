class Solution:
    def trap(self, height: List[int]) -> int:
        N = len(height)
        leftMax = height[0]
        rightMax = height[N-1]
        left = 0
        right = N-1
        total = 0

        while left < right:
            leftMax = max(leftMax, height[left])
            rightMax = max(rightMax, height[right])
            if leftMax < rightMax:
                total += leftMax - height[left]
                left += 1
            else:
                total += rightMax - height[right]
                right -= 1
        return total
