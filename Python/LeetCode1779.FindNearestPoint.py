class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        smallest = float("inf")
        idx = -1
        for i in range(len(points)):
            if points[i][0] == x or points[i][1] == y:
                d = abs(x-points[i][0]) + abs(y-points[i][1])
                if (d < smallest):
                    smallest = d
                    idx = i
        return idx