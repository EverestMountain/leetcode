import pdb


class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points = sorted(points, key=lambda x: x[1])
        p = points[0][1]
        i = 0
        n = len(points)
        need = 1
        while i < n:
            j = i + 1
            while j < n:
                if points[j][0] > p:
                    need += 1
                    break
                j += 1
            i = j
            if j < n:
                p = points[j][1]
        return need


if __name__ == "__main__":
    sol = Solution()
    # ans = sol.findMinArrowShots([[10, 16], [2, 8], [1, 6], [7, 12]])
    ans = sol.findMinArrowShots([[1, 2], [3, 4], [5, 6], [7, 8]])
    print(ans)
