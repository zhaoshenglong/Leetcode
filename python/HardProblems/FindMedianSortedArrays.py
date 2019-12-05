import math
from typing import List


class Solution:
    def find_median_sorted_arrays(self, nums1: List[int], nums2: List[int]) -> float:
        m: int = len(nums1)
        n: int = len(nums2)
        if m == 0:
            return self.find_median(nums2, n)
        if n == 0:
            return self.find_median(nums1, m)
        min_item = min(nums1[0], nums2[0])
        max_item = max(nums1[m - 1], nums2[n - 1])
        if m < n:
            t = n - m
            for i in range(t >> 1):
                nums1.insert(0, min_item)
                nums1.append(max_item)
            if t & 1 == 1:
                nums1.append(max_item)
                return self.recurse_find(nums1, 0, nums2, 0, n)[0]
            else:
                return sum(self.recurse_find(nums1, 0, nums2, 0, n)) / 2
        elif m > n:
            t = m - n
            for i in range(t >> 1):
                nums2.insert(0, min_item)
                nums2.append(max_item)
            if t & 1 == 1:
                nums2.append(max_item)
                return self.recurse_find(nums1, 0, nums2, 0, m)[0]
            else:
                return sum(self.recurse_find(nums1, 0, nums2, 0, m)) / 2
        else:
            return sum(self.recurse_find(nums1, 0, nums2, 0, n)) / 2

    def recurse_find(self, nums1: List[int], lo1: int, nums2: List[int], lo2: int, n: int) -> tuple:
        if n == 1:
            if nums1[lo1] < nums2[lo2]:
                if len(nums1) > 1 and lo1 + 1 < len(nums1):
                    if nums1[lo1 + 1] < nums2[lo2]:
                        return nums1[lo1], nums1[lo1 + 1]
                    else:
                        return nums1[lo1], nums2[lo2]
                else:
                    return nums1[lo1], nums2[lo2]
            else:
                if len(nums2) > 1 and lo2 + 1 < len(nums2):
                    if nums2[lo2 + 1] < nums1[lo1]:
                        return nums2[lo2], nums2[lo2 + 1]
                    else:
                        return nums2[lo2], nums1[lo1]
                else:
                    return nums2[lo2], nums1[lo1]
        else:
            med = (n - 1) >> 1
            if nums1[lo1 + med] == nums2[lo2 + med]:
                if nums1[lo1 + med + 1] <= nums2[lo2 + med + 1]:
                    return nums1[lo1 + med], nums1[lo2 + med + 1]
                return nums1[lo1 + med], nums2[lo2 + med + 1]
            elif nums1[lo1 + med] < nums2[lo2 + med]:
                return self.recurse_find(nums1, lo1 + (n >> 1), nums2, lo2, (n + 1) >> 1)
            else:
                return self.recurse_find(nums1, lo1, nums2, lo2 + (n >> 1), (n + 1) >> 1)

    def find_median(self, nums: List[int], l: int) -> float:
        half: int = l >> 1
        if l & 1 == 1:
            return nums[half]
        else:
            return (nums[half] + nums[half - 1]) / 2


def main():
    s = Solution()
    nums1 = [1]
    nums2 = [2, 3, 4]
    print(s.find_median_sorted_arrays(nums1, nums2))


if __name__ == '__main__':
    main()
