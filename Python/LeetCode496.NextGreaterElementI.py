class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = [-1] * len(nums1)
        mapping = {}
        for i in range(len(nums2)):
          mapping[nums2[i]] = i
        print(mapping)
        for j in range(len(nums1)):
          for i in range(mapping[nums1[j]]+1, len(nums2)):
            if nums2[i] > nums1[j]:
              ans[j] = nums2[i]
              break
        return ans