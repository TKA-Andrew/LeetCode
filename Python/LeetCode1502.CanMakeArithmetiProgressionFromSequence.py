class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        diff = 0
        for i in range(1, len(arr)):
            if arr[i] != arr[0]:
                diff = arr[i] - arr[0]
                break
        if diff == 0:
            return True
        leftover = 0
        for i in range(1, len(arr)):
            if arr[i] == arr[i-1]:
                leftover += diff
            elif arr[i] - arr[i-1] != diff:
                return False
        if leftover == 0:
            return True
        if arr[-1] - leftover - diff != 0:
            return False
        return True
        