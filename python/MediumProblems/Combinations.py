from typing import List


def recurse_combine(lo, hi, k, prev: List[int], res: List[List[int]]):
    if k == 1:
        for i in range(lo, hi - k + 2):
            t = prev.copy()
            t.append(i)
            res.append(t)
    else:
        for i in range(lo, hi - k + 2):
            t = prev.copy()
            t.append(i)
            recurse_combine(i + 1, hi, k - 1, t, res)


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        recurse_combine(1, n, k, [], res)
        return res


def main():
    s = Solution()
    print(s.combine(4, 3))


if __name__ == '__main__':
    main()



















