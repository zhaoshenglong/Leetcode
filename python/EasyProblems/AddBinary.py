class Solution:
    def addBinary(self, a: str, b: str) -> str:
        m = len(a) - 1
        n = len(b) - 1
        res = []
        spill = 0
        while m >= 0 and n >= 0:
            t = (1 if a[m] == "1" else 0) + (1 if b[n] == "1" else 0)
            if spill == 1:
                t += 1
            if t >= 2:
                t -= 2
                spill = 1
            else:
                spill = 0
            m -= 1
            n -= 1
            res.append(chr(t + 48))
        if n > m:
            a = b
            m = n

        while m >= 0:
            t = (1 if a[m] == "1" else 0) + spill
            if t >= 2:
                t -= 2
                spill = 1
            else:
                spill = 0
            m -= 1
            res.append(chr(t + 48))
        if spill == 1:
            res.append("1")
        res.reverse()
        return "".join(res)


def main():
    s = Solution()
    print(s.addBinary("1010", "1011"))


if __name__ == '__main__':
    main()
