from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        if not nums:
            return 0
        min_val = nums[0]
        sz = len(nums)
        lo = 0
        hi = sz - 1
        while lo <= hi:
            mid = (lo + hi) >> 1
            if mid - 1 >= 0 and nums[mid] < nums[mid - 1]:
                return nums[mid]
            if nums[mid] == min_val:
                i = 1
                while mid - i >= lo and mid + i <= hi:
                    if nums[mid - i] != min_val:
                        hi = mid - i
                        break
                    if nums[mid + i] != min_val:
                        lo = mid + i
                        break
                    i += 1
                if mid - i < lo:
                    lo = mid + i
                if mid + i > hi:
                    hi = mid - i
            elif nums[mid] > min_val:
                lo = mid + 1
            else:
                hi = mid - 1
        return min_val


def main():
    s = Solution()
    print(s.findMin([2, 1]))


if __name__ == '__main__':
    main()
