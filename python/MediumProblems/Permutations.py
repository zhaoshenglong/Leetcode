from typing import List


def swap(nums: List[int], i: int, j: int) -> List[int]:
    res = list.copy(nums)
    t = res[j]
    res[j] = res[i]
    res[i] = t
    return res


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        for i in range(n):
            a = swap(nums, i, 0)
            self.permute(a[1:])
        return res


def main():
    s = Solution()
    a = [1, 2, 3]
    print(s.permute(a))


if __name__ == '__main__':
    main()
