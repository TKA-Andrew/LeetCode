class Solution:
    def mySqrt(self, a: int) -> int:
        if a == 0: return 0

        # f(x) = x^2 - a, find root of f(x)
        # f'(x) = 2x
        
        # Newton's method
        # x' = x - f(x)/f'(x)
        #    = x - (x^2 - a)/2x
        #    = x - (0.5x - 0.5a/x)
        #    = (x + a/x) / 2

        # initial_guess = x = a
        x = a
        
        # equivalent to x*x > a
        while x > a/x:
            x = int((x + a/x) / 2)

        return x