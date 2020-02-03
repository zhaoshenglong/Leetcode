from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 1:
            return [[1]]
        if n == 0:
            return [[]]
        res = [[0 for i in range(n)] for i in range(n)]
        cnt = 1
        for b in range(n >> 1):
            for i in range(b, n - b):
                res[b][i] = cnt
                cnt += 1
            for j in range(b + 1, n - b):
                res[j][n - b - 1] = cnt
                cnt += 1
            for i in range(n - b - 2, b - 1, -1):
                res[n - b - 1][i] = cnt
                cnt += 1
            for j in range(n - b - 2, b, -1):
                res[j][b] = cnt
                cnt += 1
        if n & 1 == 1:
            res[n >> 1][n >> 1] = cnt
        return res


def main():
    s = Solution()
    print(s.generateMatrix(5))


if __name__ == '__main__':
    main()
