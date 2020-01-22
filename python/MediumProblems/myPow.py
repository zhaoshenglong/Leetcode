class Solution:
    def my_pow(self, x: float, n: int) -> float:
        if n == 1:
            return x
        elif n == 0:
            return 1

        if n < 0:
            return self.my_pow(1/x, -n)
        else:
            return self.my_pow(x, n >> 1) ** 2 * x if n & 1 else self.my_pow(x, n >> 1) ** 2


def main():
    s = Solution()
    print(s.my_pow(2, 10))


if __name__ == '__main__':
    main()
