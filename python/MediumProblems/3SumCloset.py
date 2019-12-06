from typing import List


class Solution:
    def three_sum_closest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = sum(nums[:3])
        nums_len = len(nums)
        for i in range(nums_len - 2):
            lo = i + 1
            hi = nums_len - 1
            remain = target - nums[i]
            if remain <= 2 * nums[i]:
                s = sum(nums[i: i + 3])
                if abs(target - s) > abs(target - res):
                    return res
                else:
                    return s
            while lo < hi:
                s = sum([nums[i], nums[lo], nums[hi]])
                if nums[lo] + nums[hi] == remain:
                    return target
                elif nums[lo] + nums[hi] < remain:
                    lo += 1
                    if abs(s - target) < abs(res - target):
                        res = s
                else:
                    hi -= 1
                    if abs(s - target) < abs(res - target):
                        res = s
        return res


def main():
    s = Solution()
    print(s.three_sum_closest([6,-18,-20,-7,-15,9,18,10,1,
                               -20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,
                               6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,
                               -9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,
                               1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,
                               0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,
                               7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,
                               16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10] ,-52))


if __name__ == '__main__':
    main()
