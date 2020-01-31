from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        sz = len(nums)
        if sz == 0:
            return -1
        if sz == 1:
            return 0 if nums[0] == target else -1
        if target == nums[0]:
            return 0

        # 在左半边
        elif target > nums[0]:
            lo = 0
            hi = sz - 1
            while lo <= hi:
                mid = (lo + hi) >> 1
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    hi = mid - 1
                elif nums[mid] >= nums[0]:
                    lo = mid + 1
                else:
                    hi = mid - 1

        # 在右半边
        else:
            lo = 0
            hi = sz - 1
            while lo <= hi:
                mid = (lo + hi) >> 1
                if nums[mid] == target:
                    return mid
                elif nums[mid] < target:
                    lo = mid + 1
                elif nums[mid] >= nums[0]:
                    lo = mid + 1
                else:
                    hi = mid - 1
        return -1


def main():
    s = Solution()
    print(s.search([1, 3], 3))


if __name__ == '__main__':
    main()
