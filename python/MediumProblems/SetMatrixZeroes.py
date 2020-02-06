from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        if m == 0:
            return
        n = len(matrix[0])
        zero = False
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    zero = True
                    matrix[i][j] = None
            if zero:
                for j in range(n):
                    if matrix[i][j] is not None:
                        matrix[i][j] = 0
                zero = False
        for j in range(n):
            for i in range(m):
                if matrix[i][j] is None:
                    matrix[i][j] = 0
                    zero = True
            if zero:
                for i in range(m):
                    if matrix[i][j] != 0:
                        matrix[i][j] = 0
            zero = False


def main():
    s = Solution()
    a = [
        [1, 1, 1],
        [1, 0, 1],
        [1, 1, 1]
    ]
    s.setZeroes(a)
    print(a)


if __name__ == '__main__':
    main()
