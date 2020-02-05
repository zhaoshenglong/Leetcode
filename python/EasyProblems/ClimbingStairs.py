class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        pp = 1
        p = 2
        res = 0
        for _ in range(2, n):
            res = pp + p
            pp = p
            p = res
        return res


def main():
    s = Solution()
    print(s.climbStairs(4))


if __name__ == '__main__':
    main()
