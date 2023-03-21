class Solution:
    def getSquare(self, n:int):
        m = 0
        while n > 0:
            x = n % 10
            n = n // 10
            m = m + (x*x)
        return m
    def isHappy(self, n: int) -> bool:
        slow = self.getSquare(n)
        fast = self.getSquare(n)
        fast = self.getSquare(fast)
        while (slow != fast):
            slow = self.getSquare(slow)
            fast = self.getSquare(fast)
            fast = self.getSquare(fast)
        if (slow == 1):
            return True
        else:
            return False
