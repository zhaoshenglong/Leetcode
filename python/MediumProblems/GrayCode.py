from typing import List


class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        elif n == 1:
            return [0, 1]
        else:
            prev = [0, 1]
            for i in range(1, n):
                r = prev.copy()
                for j in range(len(prev)):
                    prev[j] += (1 << i)
                prev.reverse()
                r.extend(prev)
                prev = r
            return prev


def main():
    s = Solution()
    print(s.grayCode(3))


if __name__ == '__main__':
    main()
