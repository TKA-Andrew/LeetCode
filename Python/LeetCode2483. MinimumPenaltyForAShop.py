# Reference: https://www.youtube.com/watch?v=0d7ShRoOFVE&t=2s

import math
class Solution:
    def bestClosingTime(self, customers: str) -> int:
        L = len(customers)
        pre_i = [0 for i in range(L + 1)]
        post_i = [0 for i in range(L + 1)]
        for i in range(1, L + 1):
            pre_i[i] = pre_i[i-1]
            if customers[i-1] == "N":
                pre_i[i] += 1
        for i in range(L - 1, -1, -1):
            post_i[i] = post_i[i+1]
            if customers[i] == "Y":
                post_i[i] += 1
        earliest = 0
        min_penalty = math.inf
        for i in range(L+1):
            p = pre_i[i] + post_i[i]
            if p < min_penalty:
                earliest = i
                min_penalty = p 
        return earliest