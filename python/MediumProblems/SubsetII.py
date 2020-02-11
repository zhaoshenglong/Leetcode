from typing import List, Dict


def recurse_subset(lo, hi, k, added: Dict, prev, nums, res):
    if k == 1:
        for i in range(lo, hi - k + 1):
            t = prev.copy()
            t.append(nums[i])
            t.sort()
            tl = tuple(t)
            if added.get(tl) is None:
                added[tl] = 1
                res.append(t)
    else:
        for i in range(lo, hi - k + 1):
            t = prev.copy()
            t.append(nums[i])
            recurse_subset(i + 1, hi, k - 1, added, t, nums, res)


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        sz = len(nums)
        if sz == 0:
            return [[]]
        else:
            res = [[], nums]
            for i in range(1, sz):
                recurse_subset(0, sz, i, {}, [], nums, res)
            return res


def main():
    s = Solution()
    print(s.subsetsWithDup([1, 2, 2, 2]))


if __name__ == '__main__':
    main()
