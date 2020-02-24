from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        if not nums:
            return 0
        sz = len(nums)
        lo = 0
        hi = sz - 1
        min_val = nums[0]
        while lo <= hi:
            mid = (lo + hi) >> 1
            if mid - 1 >= 0 and nums[mid] < nums[mid - 1]:
                return nums[mid]
            if nums[mid] >= min_val:
                # 多加一个等于号是为了防止 mid == 0这样的情况
                lo = mid + 1
            else:
                hi = mid - 1
        return min_val


def main():
    s = Solution()
    print(s.findMin([4, 5, 6, 7, -1, 1, 2]))


if __name__ == '__main__':
    main()
