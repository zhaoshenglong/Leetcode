class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if n == 1 or m == 1:
            return 1
        mat = [1 for i in range(m)]
        for i in range(1, n):
            for j in range(1, m):
                mat[j] = mat[j] + mat[j - 1]
        return mat[m - 1]


def main():
    s = Solution()
    print(s.uniquePaths(7, 2))


if __name__ == '__main__':
    main()
