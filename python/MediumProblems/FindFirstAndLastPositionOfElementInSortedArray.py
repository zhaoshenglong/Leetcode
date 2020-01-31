from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # binary search
        lo = 0
        sz = len(nums)
        if sz == 0:
            return [-1, -1]
        hi = sz - 1
        idx = -1
        while lo <= hi:
            mid = (lo + hi) >> 1
            if nums[mid] == target:
                idx = mid
                break
            elif nums[mid] > target:
                hi = mid - 1
            else:
                lo = mid + 1
        if idx == -1:
            return [-1, -1]

        # range search
        lo = idx - 1
        hi = idx + 1
        while lo >= 0 and nums[lo] == target:
            lo -= 1
        while hi <= sz - 1 and nums[hi] == target:
            hi += 1
        return [lo + 1, hi - 1]


def main():
    s = Solution()
    print(s.searchRange([2, 2], 3))


if __name__ == '__main__':
    main()
