class Solution:
    def average(self, salary: List[int]) -> float:
        maxSalary = float("-inf")
        minSalary = float("inf")
        total = 0
        for s in salary:
            minSalary = min(s, minSalary)
            maxSalary = max(s, maxSalary)
            total += s
        total = total - minSalary - maxSalary
        return total/(len(salary) - 2)