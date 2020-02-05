from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0] == 1:
            return 0
        n = len(obstacleGrid)
        if n == 1:
            for i in obstacleGrid[0]:
                if i == 1:
                    return 0
            return 1
        m = len(obstacleGrid[0])
        if m == 1:
            for m in obstacleGrid:
                if m[0] == 1:
                    return 0
            return 1
        mat = [1]

        for i in range(1, m):
            if obstacleGrid[0][i] == 1:
                mat.append(0)
            else:
                if mat[i - 1] == 0:
                    mat.append(0)
                else:
                    mat.append(1)

        for i in range(1, n):
            if obstacleGrid[i][0] == 1:
                mat[0] = 0
            for j in range(1, m):

                if obstacleGrid[i][j] == 1:
                    mat[j] = 0
                else:
                    mat[j] = mat[j] + mat[j - 1]
        return mat[m - 1]


def main():
    s = Solution()
    print(s.uniquePathsWithObstacles([
        [0, 0, 1],
        [0, 0, 0],
        [0, 0, 0]
    ]))


if __name__ == '__main__':
    main()
