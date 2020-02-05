class Solution:
    def mySqrt(self, x: int) -> int:
        mid = (1 + x) >> 1
        lo = 1
        hi = x
        while True:
            sm = pow(mid, 2)
            if sm <= x:
                smm = pow(mid + 1, 2)
                if smm > x:
                    return mid
                elif smm == x:
                    return mid + 1
                else:
                    lo = mid + 1
                    mid = (lo + hi) >> 1
            else:
                hi = mid - 1
                mid = (lo + hi) >> 1


def main():
    s = Solution()
    print(s.mySqrt(16))


if __name__ == '__main__':
    main()
