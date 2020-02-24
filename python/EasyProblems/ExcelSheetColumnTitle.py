class Solution:
    def convertToTitle(self, n: int) -> str:
        res = []
        while n > 0:
            s = int(n / 26)
            t = n - s * 26
            if t == 0:
                t = 26
                s -= 1
            res.append(chr(64 + t))
            n = s
        res.reverse()
        return "".join(res)


def main():
    s = Solution()
    print(s.convertToTitle(704))


if __name__ == '__main__':
    main()
