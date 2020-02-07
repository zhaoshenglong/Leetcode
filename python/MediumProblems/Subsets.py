from typing import List


def recurse_subset(nums, lo, sz, k, prev, res):
    if k == 1:
        for i in range(lo, sz - k + 1):
            t = prev.copy()
            t.append(nums[i])
            res.append(t)
    else:
        for i in range(lo, sz - k + 1):
            t = prev.copy()
            t.append(nums[i])
            recurse_subset(nums, i + 1, sz, k - 1, t, res)


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        sz = len(nums)
        if sz == 0:
            return [[]]
        if sz == 1:
            return [[], nums]
        res = [[i] for i in nums]
        res.append([])
        res.append(nums)
        for i in range(2, sz):
            recurse_subset(nums, 0, sz,  i, [], res)
        return res


def main():
    s = Solution()
    print(s.subsets([1, 2, 3]))


if __name__ == '__main__':
    main()
