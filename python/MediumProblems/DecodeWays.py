class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0
        elif n == 1:
            if ord(s[0]) > 48:
                return 1
            else:
                return 0
        else:
            if ord(s[0]) == 48:
                return 0
            prev_prev = 1
            prev = 1
            for i in range(1, n):
                t = 0
                if ord(s[i]) - 48 > 0:
                    t = prev
                if 10 <= int(s[i-1: i+1]) <= 26:
                    t += prev_prev
                if t == 0:
                    return 0
                prev_prev = prev
                prev = t
            return prev


def main():
    s = Solution()
    print(s.numDecodings("1100"))


if __name__ == '__main__':
    main()
