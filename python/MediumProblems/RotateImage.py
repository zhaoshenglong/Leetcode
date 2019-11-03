from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n: int = matrix.__len__()
        block_n: int = 8
        bi: int = 0
        bj: int = 0
        while bi < ((n >> 3) << 3):
            while bj < ((n >> 3) << 3):
                i: int = 0
                j: int = 0
                while i < block_n:
                    while j < block_n:
                        if bi != bj and i != j:
                            tmp: int = matrix[bi + i][bj + j]
                            matrix[bj + j][bi + i] = matrix[bi + i][bj +j]
                            matrix[bi + i][bj + j] = tmp
                        j += 1
                    i += 1
                bj += 8
            bj = 0
            bi += 8

        for i in range((n >> 3) << 3, n):
            for j in range(n):
                  tmp: int = matrix[j][i]
                matrix[j][i] = matrix[i][j]
                matrix[i][j] = tmp


def main():
    s: Solution = Solution()
    matrix: List[List[int]] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    s.rotate(matrix)
    print(matrix)


if __name__ == '__main__':
    main()
