class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        x0, y0 = coordinates[0]
        x1, y1 = coordinates[1]
        for i in range(2, len(coordinates)):
            x,y = coordinates[i]
            if (x1-x0) * (y-y1) != (x-x1) * (y1-y0):
                return False
        return True