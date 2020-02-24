from typing import List


def recurse(nums, lo, hi):
    if lo > hi:
        return None
    if lo == hi:
        if nums[lo - 1] < nums[lo] and nums[lo + 1] < nums[lo]:
            return lo
        else:
            return None
    mid = (lo + hi) >> 1
    if nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]:
        return mid
    s = recurse(nums, lo, mid - 1)
    t = recurse(nums, mid + 1, hi)
    if s:
        return s
    if t:
        return t


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if not nums:
            return 0
        sz = len(nums)
        if sz == 1:
            return 0
        elif sz == 2:
            return 0 if nums[0] > nums[1] else 1
        else:
            if nums[0] > nums[1]:
                return 0
            elif nums[-2] < nums[-1]:
                return sz - 1
            else:
                return recurse(nums, 1, sz - 2)