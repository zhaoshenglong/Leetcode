from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        lo = 0
        hi = m * n - 1
        while lo <= hi:
            mid = (lo + hi) >> 1
            i = int(mid / n)
            j = int(mid % n)
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                hi = mid - 1
            else:
                lo = mid + 1
        return False


def main():
    s = Solution()
    print(s.searchMatrix([
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
], 13))


if __name__ == '__main__':
    main()

