from typing import List


class Solution:
    def find_median_sorted_arrays(self, nums1: List[int], nums2: List[int]) -> float:
        m: int = len(nums1)
        n: int = len(nums2)
        if m == 0:
            return self.find_median(nums2, n)
        if n == 0:
            return self.find_median(nums1, m)
        if m < n:
            return self.find_helper(nums1, m, nums2, n)
        else:
            return self.find_helper(nums2, n, nums1, m)

    def find_helper(self, nums1: List[int], m: int, nums2: List[int], n: int) -> float:
        if m == 1:
            return self.direct_find(nums1[0], nums2)
        m_half = m >> 1
        m_median: float
        if m & 1 == 1:
            m_median = nums1[m_half]
        else:
            m_median = (nums1[m_half] + nums1[m_half]) / 2

        n_half = n >> 1
        n_median: float
        if n & 1 == 1:
            n_median = nums2[n_half]
        else:
            n_median = (nums2[n_half] + nums2[n_half]) / 2

        if m_median == n_median:
            return m_median

        if m & 1 == 0 and n & 1 == 0:
            if m_median < n_median:
                if nums1[m_half - 1] >= nums2[n_half - 1]:
                    return (nums1[m_half - 1] + nums1[m_half]) / 2
                else:
                    return self.find_helper(nums1[m_half + 1:], m - m_half - 1, nums2[: -m_half], n - m_half)
            else:
                if nums1[m_half] <= nums2[n_half]:
                    return (nums1[m_half - 1] + nums1[m_half]) / 2
                else:
                    return self.find_helper(nums1[:m_half], m - m_half, nums2[: -m_half], n - m_half)
        if m & 1 == 1 and n & 1 == 0:
            if m_median < n_median:
                if nums1[m_half] > nums2[n_half]:
                    return nums1[m_half]
                else:
                    return self.find_helper(nums1[m_half + 1:], m - m_half - 1, nums2[: -m_half], n - m_half)
            else:
                if nums1[m_half] <= nums2[n_half]:
                    return nums1[m_half]
                else:
                    return self.find_helper(nums1[: m_half + 1], m - m_half + 1, nums2[m_half - 1:], n - m_half + 1)
        if m & 1 == 0 and n & 1 == 1:
            if m_median > n_median:
                if nums1[m_half - 1] < nums2[n_half]:
                    return nums2[n_half]
                else:
                    return self.find_helper(nums1[m_half + 1:], m - m_half - 1, nums2[: -m_half], n - m_half)
            else:
                if nums1[m_half] >= nums2[n_half]:
                    return nums2[n_half]
                else:
                    return self.find_helper(nums1[m_half + 1:], m - m_half - 1, nums2[: -m_half], n - m_half)
        if m_median < n_median:
            return self.find_helper(nums1[m_half:], m - m_half, nums2[: -m_half], n - m_half)
        else:
            return self.find_helper(nums1[:m_half + 1], m - m_half, nums2[m_half:], n - m_half)

    def direct_find(self, num: int, nums: List[int]) -> float:
        n: int = len(nums)
        n_half = n >> 1
        if n & 1 == 1:
            if n == 1:
                return (num + nums[0]) / 2
            elif nums[n_half] <= num:
                if nums[n_half + 1] >= num:
                    return (nums[n_half] + num) / 2
                else:
                    return (nums[n_half] + nums[n_half + 1]) / 2
            else:
                if nums[n_half - 1] >= num:
                    return (nums[n_half] + num) / 2
                else:
                    return (nums[n_half] + nums[n_half - 1]) / 2
        else:
            if nums[n_half - 1] <= num <= nums[n_half]:
                return num
            elif nums[n_half] < num:
                return nums[n_half]
            else:
                return nums[n_half - 1]

    def find_median(self, nums: List[int], l: int) -> float:
        half: int = l >> 1
        if l & 1 == 1:
            return nums[half]
        else:
            return (nums[half] + nums[half - 1]) / 2


def main():
    s = Solution()
    nums1 = [1, 2]
    nums2 = [-1, 3]
    print(s.find_median_sorted_arrays(nums1, nums2))


if __name__ == '__main__':
    main()
