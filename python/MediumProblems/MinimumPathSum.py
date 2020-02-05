from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if n == 1:
            pass
        m = len(grid[0])
        mat = grid[0]
        for i in range(1, m):
            mat[i] = mat[i - 1] + grid[0][i]
        for i in range(1, n):
            mat[0] = mat[0] + grid[i][0]
            for j in range(1, m):
                mat[j] = grid[i][j] + (mat[j] if mat[j] < mat[j - 1] else mat[j - 1])
        return mat[m - 1]


def main():
    s = Solution()
    print(s.minPathSum([
  [1,3,1],
  [1,5,1],
  [4,2,1]
]))


if __name__ == '__main__':
    main()
