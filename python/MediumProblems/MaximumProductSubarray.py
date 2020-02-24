from typing import List


def recurse(nums, lo, hi) -> int:
    if lo == hi:
        return nums[lo]
    mid = (hi + lo) >> 1
    left = recurse(nums, lo, mid)
    right = recurse(nums, mid + 1, hi)
    tmp_max = left if left > right else right
    i = 0
    left_max = nums[mid]
    left_min = nums[mid]
    right_max = nums[mid + 1]
    right_min = nums[mid + 1]
    t_l = r_l = 1
    while i + mid < hi:
        t_l *= nums[mid - i]
        r_l *= nums[mid + i + 1]
        if t_l < left_min:
            left_min = t_l
        if t_l > left_max:
            left_max = t_l
        if r_l < right_min:
            right_min = r_l
        if r_l > right_max:
            right_max = r_l
        i += 1
    if not (hi - lo) & 1:
        t_l *= nums[lo]
        if t_l < left_min:
            left_min = t_l
        if t_l > left_max:
            left_max = t_l
    max_p = right_max * left_max
    if right_min * left_min > max_p:
        max_p = right_min * left_min
    return max_p if max_p > tmp_max else tmp_max


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        return recurse(nums, 0, len(nums) - 1)


def main():
    s = Solution()
    print(s.maxProduct([1, 2, -3, -1]))


if __name__ == '__main__':
    main()
