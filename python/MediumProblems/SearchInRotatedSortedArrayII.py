from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        sz = len(nums)
        if sz == 0:
            return False
        if sz == 1:
            return nums[0] == target

        if target == nums[0]:
            return True
        # 在左半边
        elif target > nums[0]:
            lo = 0
            hi = sz - 1
            while lo <= hi:
                mid = (lo + hi) >> 1
                if nums[mid] == target:
                    return True
                elif nums[mid] > target:
                    hi = mid - 1
                elif nums[mid] > nums[0]:
                    lo = mid + 1
                elif nums[mid] == nums[0]:
                    i = mid - 1
                    j = mid + 1
                    while i >= 0 and nums[i] == nums[0]:
                        i -= 1
                    while j < sz and nums[j] == nums[0]:
                        j += 1
                    if i == -1:
                        lo = j
                    if j == sz:
                        hi = i
                else:
                    hi = mid - 1

        # 在右半边
        else:
            lo = 0
            hi = sz - 1
            while lo <= hi:
                mid = (lo + hi) >> 1
                if nums[mid] == target:
                    return True
                elif nums[mid] < target:
                    lo = mid + 1
                elif nums[mid] > nums[0]:
                    lo = mid + 1
                elif nums[mid] == nums[0]:
                    i = mid - 1
                    j = mid + 1
                    while i >= 0 and nums[i] == nums[0]:
                        i -= 1
                    while j < sz and nums[j] == nums[0]:
                        j += 1
                    if i == -1:
                        lo = j
                    if j == sz:
                        hi = i
                else:
                    hi = mid - 1
        return False


def main():
    s = Solution()
    print(s.search([2, 2, 2, 0, 2, 2], 2))


if __name__ == '__main__':
    main()
