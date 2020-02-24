class Solution:
    def titleToNumber(self, s: str) -> int:
        res = ord(s[0]) - 64
        for c in s[1:]:
            res *= 26
            res += ord(c) - 64
        return res


def main():
    s = Solution()
    print(s.titleToNumber("AA"))


if __name__ == '__main__':
    main()
