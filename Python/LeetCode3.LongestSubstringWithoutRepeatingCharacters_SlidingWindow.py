# Time Complexity: O(N)
# Space Complexity: O(N)

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right, longest = 0, 0, 0
        char_count = {}

        while right < len(s):
            a = s[right]
            right += 1

            char_count[a] = char_count.get(a, 0) + 1

            while char_count[a] > 1:
                char_count[s[left]] -= 1
                left += 1

            longest = max(longest, right - left)

        return longest
